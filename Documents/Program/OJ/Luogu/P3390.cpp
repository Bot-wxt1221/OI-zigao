//************************************************************************************************
#include<algorithm>
#include<cassert>
#include<complex>
#include<cstring>
#include<memory>
#include<string>
#include<vector>
using namespace std;template <class T>
struct is_iterator{template <class U, typename enable_if<!is_convertible<U, const char *>::value, int>::type = 0>
    constexpr static auto has_indirection(int) -> decltype(*declval<U>(), bool()) {return true;}
    template <class>
    constexpr static bool has_indirection(long) {return false;}
    constexpr static bool value = has_indirection<T>(0);};using uint = unsigned int;
// Buffer size should be 2^12 or 2^13 for optimal performance with files.
const uint BUFFER_SIZE = 1 << 12;
// Maximum possible length of a string representing primitive type
// assuming we won't encounter huge double values.
const uint MAX_LENGTH = 1 << 7;namespace Detail{struct Width{uint value;};struct Fill{char value;};struct Base{uint value;};struct Precision{uint value;};struct Delimiter{const char *value;};} // namespace Detail
Detail::Width setWidth(uint value = 0) {return {value};}
Detail::Fill setFill(char value = ' ') {return {value};}
Detail::Base setBase(uint value = 10){assert(2 <= value && value <= 36);return {value};}
Detail::Precision setPrecision(uint value = 9){assert(value < MAX_LENGTH);return {value};}
Detail::Delimiter setDelimiter(const char *value = " ") {return {value};}
/******************************* input classes ********************************/
class InputDevice{
protected:
    const char *head;const char *tail;InputDevice(const char *head, const char *tail) : head(head), tail(tail), base(setBase().value) {}
    virtual void fillInput() = 0;char nextChar(){if (__builtin_expect(head >= tail, false))
            fillInput();return *head++;}
    template <class I>
    int readUnsignedIntGeneral(I &arg, char c){I value = 0;int length = 0;for (;; ++length, c = nextChar()){if (isDigit(c))
                c -= '0';else if (isUpper(c))
                c -= 'A' - 10;else if (isLower(c))
                c -= 'a' - 10;else
                c = base;if (c >= base)
                break;value = base * value + c;}
        arg = value;return --head, length;}
    template <class I>
    int readUnsignedInt(I &arg, char c){if (__builtin_expect(base > 10, false))
            return readUnsignedIntGeneral(arg, c);I value = 0;int length = 0;for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
            value = base * value + c - '0';arg = value;return --head, length;}
    template <class I>
    bool readSignedInt(I &arg, char c){bool negative = c == '-';if (negative)
            c = nextChar();typename make_unsigned<I>::type unsignedArg;if (readUnsignedInt(unsignedArg, c) == 0)
            return false;arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);return true;}
    template <class F>
    bool readFloatingPoint(F &arg, char c){bool negative = c == '-';if (negative)
            c = nextChar();unsigned long long integerPart;if (readUnsignedInt(integerPart, c) == 0)
            return false;arg = static_cast<F>(integerPart);if (nextChar() == '.'){unsigned long long fractionalPart = 0;int fractionalLength = readUnsignedInt(fractionalPart, nextChar());if (fractionalLength > 0){unsigned long long basePower = 1;for (; fractionalLength; --fractionalLength)
                    basePower *= base;arg += static_cast<F>(fractionalPart) / basePower;}
       }
        else
            --head;if (negative)
            arg = -arg;return true;}
public:
    uint base;InputDevice(InputDevice const &) = delete;InputDevice &operator=(InputDevice const &) = delete;static bool isSpace(char c) {return static_cast<unsigned char>(c - '\t') < 5 || c == ' ';}
    static bool isDigit(char c) {return static_cast<unsigned char>(c - '0') < 10;}
    static bool isUpper(char c) {return static_cast<unsigned char>(c - 'A') < 26;}
    static bool isLower(char c) {return static_cast<unsigned char>(c - 'a') < 26;}
    static bool isOneOf(char c, const char *str) {return strchr(str, c) != nullptr;}
    void putBack() {--head;} // can be called only once directly after successfully reading a character
    bool readChar(char &arg){if (__builtin_expect(head >= tail, false)){fillInput();if (__builtin_expect(head >= tail, false))
                return arg = '\0', false;}
        return arg = *head++, true;}
    template <class UnaryPredicate>
    char skipCharacters(UnaryPredicate isSkipped){char c;do{c = nextChar();} while (isSkipped(c));return c;}
    char skipCharacters() {return skipCharacters(isSpace);}
    template <class UnaryPredicate>
    int readString(char *arg, int limit, UnaryPredicate isTerminator){skipCharacters(isTerminator);// put back first non-skipped character, reserve space for null character
        int charsRead = 0;for (--head, --limit; head < tail; fillInput()){ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), isTerminator) - head;arg = copy_n(head, chunkSize, arg);head += chunkSize;charsRead += chunkSize;if (chunkSize == 0 || head < tail)
                break;}
        return *arg = '\0', charsRead;}
    int readString(char *arg, int limit, const char *terminators){if (!*terminators)
            return readString(arg, limit, InputDevice::isSpace);return readString(arg, limit, [terminators](char c){return InputDevice::isOneOf(c, terminators);});}
    // property setters
    bool read(Detail::Base newBase){base = newBase.value;return true;}
    // primitive types
    bool read() {return true;}
    bool read(char &arg) {return readChar(arg);}
    template <class I>
    typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
                              bool>::type
    read(I &arg) {return readUnsignedInt(arg, skipCharacters()) > 0;}
    template <class I>
    typename enable_if<is_integral<I>::value && is_signed<I>::value,
                              bool>::type
    read(I &arg) {return readSignedInt(arg, skipCharacters());}
    template <class F>
    typename enable_if<is_floating_point<F>::value,
                              bool>::type
    read(F &arg) {return readFloatingPoint(arg, skipCharacters());}
    // characters skip
    bool read(const char &arg){skipCharacters([arg](char c){return arg != c;});return true;}
    bool read(const char *arg){if (*arg)
            skipCharacters([arg](char c){return InputDevice::isOneOf(c, arg);});else
            skipCharacters();return putBack(), true;}
    bool read(bool (*isSkipped)(char)){skipCharacters(isSkipped);putBack();return true;}
    // strings
    template <class I, class Terminator, class... Ts>
    typename enable_if<is_integral<I>::value,
                              bool>::type
    read(char *arg, I limit, Terminator terminator, Ts &&...args){readString(arg, static_cast<int>(limit), terminator);return read(forward<Ts>(args)...);}
    template <class I>
    typename enable_if<is_integral<I>::value,
                              bool>::type
    read(char *arg, I limit) {return read(arg, limit, "");}
    template <class... Ts>
    bool read(char *first, char *last, Ts &&...args){return read(first, static_cast<int>(last - first), forward<Ts>(args)...);}
    template <int N, class... Ts>
    bool read(char (&arg)[N], Ts &&...args) {return read(static_cast<char *>(arg), N, forward<Ts>(args)...);}
    template <class Terminator, class... Ts>
    bool read(string &arg, Terminator terminator, Ts &&...args){for (int length = 16, last = 0;; last += length, length <<= 1){arg.resize(last + length);int charsRead = readString(&arg[last], length + 1, terminator);if (charsRead < length){arg.resize(last + charsRead);return read(forward<Ts>(args)...);}
       }
   }
    bool read(string &arg) {return read(arg, "");}
    // complex types and ranges
    template <class T1, class T2>
    bool read(pair<T1, T2> &arg) {return read(arg.first, arg.second);}
    template <class T>
    bool read(complex<T> &arg){T real, imag;if (!read(real, imag))
            return false;arg.real(real), arg.imag(imag);return true;}
    template <class T>
    bool read(vector<T> &arg){uint n;if (!read(n))
            return false;arg.resize(n);return read(arg.begin(), arg.end());}
    template <class Iterator, class... Ts>
    typename enable_if<is_iterator<Iterator>::value,
                              bool>::type
    read(Iterator first, Iterator last, Ts &&...args){for (; first != last; ++first)
            if (!read(*first))
                return false;return read(forward<Ts>(args)...);}
    template <class Iterator, class I, class... Ts>
    typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
                              bool>::type
    read(Iterator first, I count, Ts &&...args) {return read(first, first + count, forward<Ts>(args)...);}
    // generic forwarding
    template <class T>
    auto read(T &arg) -> decltype(arg.read(*this)) {return arg.read(*this);}
    template <class T0, class T1, class... Ts>
    typename enable_if<!is_iterator<T0>::value && !is_convertible<T0, char *>::value,
                              bool>::type
    read(T0 &&arg0, T1 &&arg1, Ts &&...args){return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);}};class InputFile : public InputDevice{FILE *file;bool lineBuffered;bool owner;char buffer[BUFFER_SIZE];void fillInput() override{head = buffer;*buffer = '\0';if (__builtin_expect(!lineBuffered, true)){tail = head + fread(buffer, 1, BUFFER_SIZE, file);}
        else{tail = head;if (fgets(buffer, BUFFER_SIZE, file))
                while (*tail)
                    ++tail;}
   }
public:
    InputFile(FILE *file = stdin, bool lineBuffered = true, bool takeOwnership = false)
        : InputDevice(buffer, buffer), file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
    InputFile(const char *fileName) : InputFile(fopen(fileName, "r"), false, true) {}
    ~InputFile(){if (owner)
            fclose(file);}};// Picks up data appended to the string but doesn't handle reallocation.
class InputString : public InputDevice{void fillInput() override{while (*tail)
            ++tail;}
public:
    InputString(const string &s) : InputDevice(s.data(), s.data() + s.size()) {}
    InputString(const char *s) : InputDevice(s, s + strlen(s)) {}};/******************************* output classes *******************************/
class OutputDevice{
protected:
    char buffer[BUFFER_SIZE + MAX_LENGTH];char *output;char *end;bool separate;OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false), width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value), delimiter(setDelimiter().value) {computeBasePower();}
    virtual void writeToDevice(uint count) = 0;void flushMaybe(){if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)){writeToDevice(BUFFER_SIZE);output = copy(buffer + BUFFER_SIZE, output, buffer);}
   }
    void computeBasePower(){basePower = 1;for (uint i = 0; i < precision; ++i)
            basePower *= base;}
    template <class I>
    char *writeUnsignedInt(I arg, char *last){if (__builtin_expect(arg == 0, false))
            *--last = '0';if (__builtin_expect(base == 10, true)){for (; arg; arg /= 10)
                *--last = '0' + arg % 10;}
        else
            for (; arg; arg /= base){I digit = arg % base;*--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;}
        return last;}
    template <class I>
    char *writeSignedInt(I arg, char *last){auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);if (arg < 0){last = writeUnsignedInt(~unsignedArg + 1, last);*--last = '-';return last;}
        return writeUnsignedInt(unsignedArg, last);}
    template <class F>
    char *writeFloatingPoint(F arg, char *last){bool negative = signbit(arg);if (negative)
            arg = -arg;if (isnan(arg))
            for (int i = 0; i < 3; ++i)
                *--last = i["NaN"];else if (isinf(arg))
            for (int i = 0; i < 3; ++i)
                *--last = i["fnI"];else{auto integerPart = static_cast<unsigned long long>(arg);auto fractionalPart = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));if (fractionalPart >= basePower)
                ++integerPart, fractionalPart = 0;char *point = last - precision;if (precision > 0){::fill(point, writeUnsignedInt(fractionalPart, last), '0');*--point = '.';}
            last = writeUnsignedInt(integerPart, point);}
        if (negative)
            *--last = '-';return last;}
    int writeT(char *first){int delimiterLenght = separate ? writeDelimiter() : 0;separate = true;uint charsWritten = static_cast<uint>(end - first);if (__builtin_expect(charsWritten < width, false))
            charsWritten += writeFill(width - charsWritten);output = copy(first, end, output);flushMaybe();return delimiterLenght + static_cast<int>(charsWritten);}
    int writeFill(uint count){int charsWritten = static_cast<int>(count);if (__builtin_expect(output + count + MAX_LENGTH < end, true)){if (count == 1)
                *output++ = fill;else
                output = fill_n(output, count, fill);}
        else
            for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE){if (chunkSize > count)
                    chunkSize = count;output = fill_n(output, chunkSize, fill);flushMaybe();if ((count -= chunkSize) == 0)
                    break;}
        return charsWritten;}
public:
    uint width;char fill;uint base;uint precision;unsigned long long basePower;string delimiter;OutputDevice(OutputDevice const &) = delete;OutputDevice &operator=(OutputDevice const &) = delete;virtual ~OutputDevice(){};int writeChar(char arg){separate = false;*output++ = arg;flushMaybe();return 1;}
    int writeString(const char *arg, size_t length, bool checkWidth = true){separate = false;uint count = static_cast<uint>(length);int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);if (__builtin_expect(output + count + MAX_LENGTH < end, true)){if (count == 1)
                *output++ = *arg;else
                output = copy_n(arg, count, output);}
        else
            for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE){if (chunkSize > count)
                    chunkSize = count;output = copy_n(arg, chunkSize, output);flushMaybe();if ((count -= chunkSize) == 0)
                    break;arg += chunkSize;}
        return charsWritten;}
    int writeDelimiter() {return writeString(delimiter.c_str(), delimiter.size(), false);}
    void flush(){writeToDevice(static_cast<uint>(output - buffer));output = buffer;}
    // property setters
    int write(Detail::Width newWidth){width = newWidth.value;return 0;}
    int write(Detail::Fill newFill){fill = newFill.value;return 0;}
    int write(Detail::Base newBase){base = newBase.value;computeBasePower();return 0;}
    int write(Detail::Precision newPrecision){precision = newPrecision.value;computeBasePower();return 0;}
    int write(Detail::Delimiter newDelimiter){delimiter = newDelimiter.value;return 0;}
    // primitive types
    int write() {return 0;}
    int write(char arg) {return writeChar(arg);}
    template <class I>
    typename enable_if<is_integral<I>::value && is_unsigned<I>::value,int>::type
    write(I arg) {return writeT(writeUnsignedInt(arg, end));}
    template <class I>
    typename enable_if<is_integral<I>::value && is_signed<I>::value,int>::type
    write(I arg) {return writeT(writeSignedInt(arg, end));}
    template <class F>
    typename enable_if<is_floating_point<F>::value,int>::type
    write(F arg) {return writeT(writeFloatingPoint(arg, end));}
    // complex types
    int write(const char *arg) {return writeString(arg, strlen(arg));}
    template <int N>
    int write(char (&arg)[N]) {return writeString(arg, strlen(arg));}
    int write(const string &arg) {return writeString(arg.c_str(), arg.size());}
    template <class T1, class T2>
    int write(const pair<T1, T2> &arg){int charsWritten = write(arg.first);charsWritten += writeDelimiter();return charsWritten + write(arg.second);}
    template <class T>
    int write(const complex<T> &arg) {return write(real(arg), imag(arg));}
    // ranges
    template <class Iterator, class... Ts>
    typename enable_if<is_iterator<Iterator>::value,int>::type
    write(Iterator first, Iterator last, Ts &&...args){int charsWritten = 0;for (; first != last; charsWritten += ++first == last ? 0 : writeDelimiter())
            charsWritten += write(*first);return charsWritten + write(forward<Ts>(args)...);}
    template <class Iterator, class I, class... Ts>
    typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,int>::type
    write(Iterator first, I count, Ts &&...args) {return write(first, first + count, forward<Ts>(args)...);}
    // generic forwarding
    template <class T>
    auto write(const T &arg) -> decltype(arg.write(*this)) {return arg.write(*this);}
    template <class T0, class T1, class... Ts>
    typename enable_if<!is_iterator<T0>::value,int>::type
    write(T0 &&arg0, T1 &&arg1, Ts &&...args){int charsWritten = write(forward<T0>(arg0));return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);}};class OutputFile : public OutputDevice{FILE *file;bool owner;void writeToDevice(uint count) override{fwrite(buffer, 1, count, file);fflush(file);}
public:
    OutputFile(FILE *file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
    OutputFile(const char *fileName) : OutputFile(fopen(fileName, "w"), true) {}
    ~OutputFile() override{flush();if (owner)
            fclose(file);}};class OutputString : public OutputDevice{string &str;void writeToDevice(uint count) override {str.append(buffer, count);}
public:
    OutputString(string &str) : OutputDevice(), str(str) {}
    ~OutputString() override {flush();}};unique_ptr<InputDevice> input;
unique_ptr<OutputDevice> output;template <class... Ts>
bool read(Ts &&...args) {return input->read(forward<Ts>(args)...);}
template <class... Ts>
int write(Ts &&...args) {return output->write(forward<Ts>(args)...);}
template <class... Ts>
int writeln(Ts &&...args) {return write(forward<Ts>(args)..., '\n');}
void flush() {output->flush();}
//************************************************************************************************
#include<cstring>
#define MATRIX_MOD %1000000007
#define MATRIX_TYPE long long
const int MATRIX_MAX_N=100;
const int MATRIX_MAX_M=100;
struct MATRIX{
    int n,m;
    MATRIX_TYPE matrix[MATRIX_MAX_N][MATRIX_MAX_M];

    void operator = (const MATRIX &a){
        n=a.n;
        m=a.m;
        for(register int i=0;i<n;++i)
            for(register int j=0;j<m;++j)
                matrix[i][j]=a.matrix[i][j];
    }

    MATRIX operator + (const MATRIX &a) const {
        MATRIX ans;
        ans.n=n;
        ans.m=m;
        for(register int i=0;i<n;++i)
            for(register int j=0;j<m;++j)
                ans.matrix[i][j]=(matrix[i][j]+a.matrix[i][j])MATRIX_MOD;

        return ans;
    }

    MATRIX operator * (const MATRIX &a) const {
        MATRIX ans;
        ans.n=n;
        ans.m=a.m;
        memset(ans.matrix,0,sizeof(ans.matrix));
        for(register int i=0;i<n;++i)
            for(register int k=0;k<m;++k)
                for(register int j=0;j<a.m;++j)
                    ans.matrix[i][j]=(ans.matrix[i][j]+matrix[i][k]*a.matrix[k][j]MATRIX_MOD)MATRIX_MOD;

        return ans;
    }

    friend MATRIX operator ^ (MATRIX base,MATRIX_TYPE exponential){
        MATRIX ans;
        ans.n=base.n;
        ans.m=base.n;
        memset(ans.matrix,0,sizeof(ans.matrix));

        for(register int i=0;i<base.n;++i)
            ans.matrix[i][i]=1;

        while(exponential){
            if(exponential&1) ans=ans*base;
            base=base*base;
            exponential>>=1;
        }

        return ans;
    }

    void print(){
        for(register int i=0;i<n;++i){
            for(register int j=0;j<n;++j)
                printf("%d ",matrix[i][j]MATRIX_MOD);
            putchar('\n');
        }

        return;
    }
}m;
int main(){
    // freopen("P3390_1.in", "r", stdin);
    // FILE *fp=fopen("P3390_1.in", "r");
    // FILE *fp2=fopen("P3390.out", "w");
    input.reset(new InputFile(stdin, true));
    output.reset(new OutputFile(stdout, false));
    int n;
    long long x;
    read(n);
    read(x);
    for(register int i=0;i<n;++i)
        read(m.matrix[i],n);
    m=m^x;
    for(register int i=0;i<n;++i)
        writeln(m.matrix[i],n);
    return 0;
}