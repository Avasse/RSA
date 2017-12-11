#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>

using namespace std;

int getN(int P, int Q) {
    return P*Q;
}

int getFi(int P, int Q) {
    return (P - 1)*(Q - 1);
}

unsigned int pgcd(unsigned int a,unsigned int b) {
    return b ?  pgcd(b,a%b) : a;
}

int getRandomPrimeNumber(int FI) {
    vector<int> results;

    for (int  i =  2;  FI > 0;  ++i) {
        bool isPrime = true;
        for (int j = 2; j < i; ++j) {
            if (i % j ==  0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            --FI;
            results.push_back(i);
        }
    }

    int random ;
    srand(time(0)); // This will ensure a really randomized number by help of time.
    random = rand() % results.size();

    return results[random];
}

int modInverse(int n, int p) {
    n %= p;
    for(int x = 1; x < p; x++) {
        if((n*x) % p == 1) return x;
    }
}

int getD(int a, int b) {
    // r = PGCD(a, b) et r = au + bv

    int r = a, u = 1, v = 0;
    int rp = b; int up = 0; int vp = 1;

    int q, rs, us, vs;
    while (rp != 0) {
        q = r / rp;
        rs = r; us = u; vs = v;
        r = rp; u = up; v = vp;
        rp = rs - q * rp; up = us - q * up; vp = vs - q * vp;
    }

    //vector used to return multiple values;
    //vector<int> results (3);
    //vector<int> results (2);
    //results[0] = r;
    //results[1] = u;
    //results[2] = v;

    if (u > 2) return u;
    else return u+b;
}

int pM(int b, int e, int m) {
    int c = 1;
    int ep = 0;
    while (ep < e){
        c = (b * c) % m;
        ep++;
    }
    return c;
}

int encryptChar(char caracter, int e, int n) {
    int c = int(caracter);
    int encryptedChar = pM(c, e, n);
    return encryptedChar;
}

int decryptChar(int caracter, int d, int n) {
    int decryptedChar = pM(caracter, d, n);
    return decryptedChar;
}

int main() {

    int p = 3;
    int q = 5;
    int n = getN(p, q);
    int fi = getFi(p, q);
    int e = getRandomPrimeNumber(fi);
    int d = getD(e, fi);
    vector<int> publicKey = {n, e};
    vector<int> privateKey = {n, d};

    char c = 'A';
    int encrypted = encryptChar(c, e, n);

    int decrypted = decryptChar(encrypted, d, n);

    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_HELLO THIS IS A RSA TP WITH 2 PREDEFINED PRIME NUMBERS *_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;

    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_CHAR 'A' RESULTS WITH p = 3 / q = 5 _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;

    cout << "With little couple of values (p, q)" << endl;
    cout << "Results : " << endl;
    cout << "'A' Encrypted (decimal) : " << encrypted << endl;
    cout << "(decimal) " << encrypted << " Decrypted (decimal) : " << decrypted << endl;

    cout << "=> => => => => ERROR : With p = 3 and q = 5, we cannot retrieve decrypted char cause n is <= full Ascii codes for letters" << endl << endl;


    int p2 = 73;
    int q2 = 83;
    int n2 = getN(p2, q2);
    int fi2 = getFi(p2, q2);
    int e2 = getRandomPrimeNumber(fi2);
    int d2 = getD(e2, fi2);
    vector<int> publicKey2 = {n2, e2};
    vector<int> privateKey2 = {n2, d2};

    char c2 = 'A';
    int encrypted2 = encryptChar(c2, e2, n2);

    int decrypted2 = decryptChar(encrypted2, d2, n2);

    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_CHAR 'A' RESULTS WITH p = 73 / q = 83 _*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl << endl;

    cout << "With large couple of values (p, q)" << endl;
    cout << "Results : " << endl;
    cout << "'A' Encrypted (decimal) : " << encrypted2 << endl;
    cout << "(decimal) " << encrypted2 << " Decrypted (decimal) : " << decrypted2 << endl;

    cout << "Enter something to exit. Thanks you.";
    int exit;
    cin >> exit;
    return 0;
}