//Igor Lonak

void StringRev1(std::string &s1, std::string &output, int &i) {
    if (i >= 0) {
        output += s1[i];
        i--;
        StringRev1(s1, output, i);
    }
}

void StringRev(std::string &s1) {
    std::string output;
    int i = s1.size() - 1;
    StringRev1(s1, output, i);
    s1 = output;
}

int Compare1(std::string &s1, std::string &s2, int &i) {
    if (i <= s1.size()) {
        if (s1[i] > s2[i])
        {
            return 1;
        }
        else if (s1[i] < s2[i])
        {
            return 0;
        }
        i++;
        return Compare1(s1, s2, i);
    }
    return 3;
}

bool Compare(std::string& s1,std::string& s2){
    if( s1.size() > s2.size() )
        return true;
    if( s1.size() < s2.size() )
        return false;

    int i = 0;
    int tmp = Compare1(s1,s2,i);
    if (tmp == 1){
        return true;
    }
    else if (tmp == 0){
        return false;
    }
    return false;
}

void Add1(std::string &s1, std::string &s2, std::string &output, int &carry, int &sum, int &i, int &s1Size) {
    if (i < s1Size) {
        sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        output += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        Add1(s1, s2, output, carry, sum, i, s1Size);
    }
}

void Add2(std::string &s1, std::string &s2, std::string &output, int &carry, int &sum, int &i, int &s2Size) {
    if (i < s2Size) {
        sum = (s2[i] - '0') + carry;
        output += (sum % 10 + '0');
        carry = sum / 10;
        i++;
        Add2(s1, s2, output, carry, sum, i, s2Size);
    }
}

std::string Add(std::string s1, std::string s2) {
    std::string output = "";
    int sum = 0;
    int carry = 0;
    if (s1.size() > s2.size())
        s1.swap(s2);

    StringRev(s1);
    StringRev(s2);
    int s1Size = s1.size();
    int s2Size = s2.size();

    int i = 0;
    Add1(s1, s2, output, carry, sum, i, s1Size);

    i = s1Size;
    Add2(s1, s2, output, carry, sum, i, s2Size);

    if (carry)
        output += (carry + '0');
    StringRev(output);
    return output;
}


void Sub2 (std::string &s1 , std::string &s2 , int &k , int &sum , int &carry , int &s1Size, int &s2Size , std::string &output) {

    if (k < s1Size) {
        sum = (s1[k] - '0') - carry;
        if (sum < 0) {
            sum += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        output += (sum + '0');
        k ++;
        Sub2(s1, s2, k, sum, carry, s1Size, s2Size, output);
    }
}


void Sub1 (std::string &s1 , std::string &s2 , int &i , int &sum , int &carry , int &s2Size , std::string &output){

    if (i < s2Size){
        sum = (s1[i] - '0') - (s2[i] - '0') - carry;
        if(sum < 0){
            sum += 10;
            carry = 1;

        } else {

            carry = 0;
        }
        output += (sum + '0');
        i ++;
        Sub1(s1, s2, i, sum, carry, s2Size, output);
    }
}


std::string Sub( std::string s1, std::string s2 ) {
    std::string output = "";
    int sum = 0;
    int carry = 0;

    StringRev(s1);
    StringRev(s2);
    int s1Size = s1.size();
    int s2Size = s2.size();

    int i = 0;

    Sub1(s1, s2, i, sum, carry, s2Size, output);

    int k = s2Size;

    Sub2(s1, s2, k, sum, carry, s1Size, s2Size, output);

    StringRev( output );

    int pom= output.find_first_not_of('0');
    if( pom>= output.size())
        output = "0";
    else
        output.erase(0, pom);

    return output;
}

std::string PartSum(std::string s1, std::string s2) {
    bool nots1 = false;
    bool nots2 = false;
    std::string output = "";

    if (s1.size() > 0 && s1[0] == '+')
        s1 = s1.substr(1);
    if (s2.size() > 0 && s2[0] == '+')
        s2 = s2.substr(1);


    if (s1.size() > 0 && s1[0] == '-') {
        nots1 = true;
        s1 = s1.substr(1);
    }
    if (s2.size() > 0 && s2[0] == '-') {
        nots2 = true;
        s2 = s2.substr(1);
    }

    if (!nots1 && !nots2)
        output = Add(s1, s2);
    else if (nots1 && nots2) {
        output = Add(s1, s2);
        output = "-" + output;
    } else {
        if (nots1) {
            if (Compare(s1, s2)) {
                output = Sub(s1, s2);
                if (output != "0")
                    output = "-" + output;
            } else
                output = Sub(s2, s1);
        } else {
            if (Compare(s2, s1)) {
                output = Sub(s2, s1);
                if (output != "0")
                    output = "-" + output;
            } else
                output = Sub(s1, s2);
        }
    }
    return output;
}


void Sum1 (std::string &output, int &i, int &set, const std::string *data){
    if( i < set){
        output = PartSum(output, data[i]);
        i++;
        Sum1(output, i, set, data);
    } else {
        return;
    }
}

std::string Sum(int set, const std::string *data) {
    std::string output = "0";
    int i = 0;
    Sum1(output, i, set, data);
    return output;
}

void Sum2 (int &set, std::string &output, std::string &tmp, va_list &argus){
    if (set > 0){
        tmp = va_arg(argus, char*);
        output = PartSum(output, tmp);
        set--;
        Sum2(set,output,tmp,argus);
    }
}

std::string Sum(int set, ...) {
    std::string output = "0";
    std::string tmp;
    va_list argus;
    va_start(argus, set);
    Sum2(set,output,tmp,argus);
    va_end(argus);
    return output;
}

void Sum(std::string *output, int set, const std::string *data) {
    *output = Sum(set, data);
}

void Sum3 (std::string *output, int &set, std::string &tmp, va_list &argus){
    if(set > 0){
        tmp = va_arg(argus, char*);
        *output = PartSum(*output, tmp);
        set--;
        Sum3(output, set, tmp, argus);
    }
}

void Sum(std::string *output, int set, ...) {
    *output = "0";
    std::string tmp;
    va_list argus;
    va_start(argus, set);
    Sum3(output, set, tmp, argus);
    va_end(argus);
}

void Sum(std::string &output, int set, const std::string *data) {
    Sum(&output, set, data);
}


void Sum(std::string &output, int set, ...) {
    output = "0";
    std::string tmp;
    va_list argus;
    va_start(argus, set);
    Sum2(set,output,tmp,argus);
    va_end(argus);
}


void Move1(std::string &s1, int &i, int &n) {
    if (i < n) {
        s1 += "0";
        i++;
        Move1(s1, i, n);
    }
}

void Move(std::string &s1, int n) {
    int i = 0;
    Move1(s1, i, n);
}

void PartMult2(std::string &s1, std::string &s2, std::string &tmp, std::string &output, int &j) {
    if (j > 0) {
        tmp = Add(tmp, s1);
        j--;
        PartMult2(s1, s2, tmp, output, j);
    }
}


void PartMult1(std::string &s1, std::string &s2, std::string &tmp, std::string &output, int &i) {
    if (i >= 0) {
        tmp = "0";
        int j = s2[i] - '0';
        PartMult2(s1, s2, tmp, output, j);
        Move(tmp, s2.size() - 1 - i);
        output = Add(output, tmp);
        i--;
        PartMult1(s1, s2, tmp, output, i);
    }
}


std::string PartMult(std::string s1, std::string s2) {

    bool s1Neg = false;
    bool s2Neg = false;
    std::string output;
    std::string tmp;

    if (s1.size() > 0 && s1[0] == '+')
        s1 = s1.substr(1);
    if (s2.size() > 0 && s2[0] == '+')
        s2 = s2.substr(1);

    if (s1.size() > 0 && s1[0] == '-') {
        s1Neg = true;
        s1 = s1.substr(1);
    }
    if (s2.size() > 0 && s2[0] == '-') {
        s2Neg = true;
        s2 = s2.substr(1);
    }

    if (s1 == "0" || s2 == "0")
        return "0";

    int i = s2.size() - 1;
    PartMult1(s1, s2, tmp, output, i);

    if (s1Neg ^ s2Neg)
        output = "-" + output;

    return output;
}

void Mult1(int &set, const std::string *data, std::string &output, int &i) {
    if (i < set) {
        output = PartMult(output, data[i]);
        i++;
        Mult1(set, data, output, i);
    }
}


std::string Mult(int set, const std::string *data) {
    std::string output = "1";
    int i = 0;
    Mult1(set, data, output, i);
    return output;
}

void Mult2(int &set, std::string &tmp, std::string &output, va_list &argus) {
    if (set-- > 0) {
        tmp = va_arg(argus, char*);
        output = PartMult(output, tmp);
        Mult2(set, tmp, output, argus);
    }

}

std::string Mult(int set, ...) {
    std::string output = "1";
    std::string tmp;
    va_list argus;
    va_start(argus, set);
    Mult2(set, tmp, output, argus);
    va_end(argus);
    return output;
}

void Mult(std::string *output, int set, const std::string *data) {
    *output = Mult(set, data);
}


void Mult3(int &set, std::string &tmp, std::string *output, va_list& argus) {
    if (set-- > 0) {
        tmp = va_arg( argus, char*);
        *output = PartMult(*output, tmp );
        Mult3(set, tmp, output, argus);
    }

}

void Mult(std::string* output, int set, ... ){
    *output = "1";
    std::string tmp;
    va_list argus;
    va_start(argus, set );
    Mult3(set, tmp, output, argus);
    va_end(argus );
}


void Mult(std::string &output, int set, const std::string *data) {
    Mult(&output, set, data);
}


void Mult(std::string &output, int set, ...) {
    output = "1";
    std::string tmp;
    va_list argus;
    va_start(argus, set);
    Mult2(set, tmp, output, argus);
    va_end(argus);
}

std::string Operation(std::string (*funct)(int, const std::string *), int set, const std::string *data) {
    return funct(set, data);
}

void Operation1(int &set, std::string *data, int &i, va_list& argus) {
    if (i < set) {
        data[i] = va_arg(argus, char*);
        i++;
        Operation1(set, data, i, argus);
    }

}

std::string Operation(std::string (*funct)(int, const std::string *), int set, ...) {
    std::string *data = new std::string[set];
    va_list argus;
    va_start(argus, set);
    int i = 0;
    Operation1(set, data, i, argus);
    va_end(argus);

    std::string output = Operation(funct, set, data);
    delete[] data;
    return output;
}

void Operation(std::string *output, std::string (*funct)(int, const std::string *), int set, ...) {

    std::string *data = new std::string[set];
    va_list argus;
    va_start(argus, set);
    int i = 0;
    Operation1(set, data, i, argus);
    va_end(argus);

    *output = Operation(funct, set, data);
    delete[] data;
}

void Operation(std::string *output, std::string (*funct)(int, const std::string *), int set, const std::string *data) {
    *output = funct(set, data);
}

void Operation(std::string &output, std::string (*funct)(int, const std::string *), int set, ...) {

    std::string *data = new std::string[set];
    va_list argus;
    va_start(argus, set);
    int i = 0;
    Operation1(set, data, i, argus);
    va_end(argus);

    output = Operation(funct, set, data);
    delete[] data;
}

void Operation(std::string &output, std::string (*funct)(int, const std::string *), int set, const std::string *data) {
    output = funct(set, data);
}

