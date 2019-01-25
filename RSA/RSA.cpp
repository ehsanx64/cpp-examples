// RSA.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "RSA.h"
#include "tools.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j;
char en[50], m[50];
char msg[100];


int main() {
	// Get the first prime number
	cout << "Please enter first prime number: ";
	cin >> x;

	// If the number is not a prime show an error and exit
	flag = prime(x);
	if (flag == 0) {
		cout << "The number is not a prime number.";
		exit(0);
	}

	// Get the second prime number
	cout << "Please enter second prime number: ";
	cin >> y;

	// If the second number is not a prime or is equal to first number exit program
	flag = prime(y);
	if (flag == 0 || x == y) {
		cout << "No prime numbers given";
		exit(0);
	}

	// Get the user string and store it in a buffer
	cout << "Enter your text to encrypt: ";
	cin >> msg;

	for (i = 0; msg[i] != NULL; i++) {
		m[i] = msg[i];
	}
		
	n = x * y;
	t = (x - 1) * (y - 1);

	encryption_key();
	cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";

	for (i = 0; i < j - 1; i++)
		cout << "\n" << e[i] << "\t" << d[i];

	cout << endl;

	encrypt();
	decrypt();

	waitForEnter();

	return 0;
} //end of the main program

/*
** Check if the given number is prime. Returns 1 if argument is prime 0 otherwise.
*/
int prime(long int pr) {
	int i;
	j = sqrt(pr);
	for (i = 2; i <= j; i++) {
		if (pr % i == 0)
			return 0;
	}
	return 1;
}

/*
** Generate a key for encryption
*/
void encryption_key() {
	int k = 0;

	for (i = 2; i < t; i++) {
		if (t % i == 0)
			continue;

		flag = prime(i);

		if (flag == 1 && i != x && i != y) {
			e[k] = i;
			flag = cd(e[k]);

			if (flag > 0) {
				d[k] = flag;
				k++;
			}

			if (k == 99)
				break;
		}
	}
}

long int cd(long int a) {
	long int k = 1;

	while (1) {
		k = k + t;

		if (k % a == 0)
			return(k / a);
	}
}

/*
** Encrypt the string buffer using the generated key
*/
void encrypt() {
	long int pt, ct, key = e[0], k, len;
	i = 0;
	len = strlen(msg);

	while (i != len) {
		pt = m[i];
		pt = pt - 96;
		k = 1;

		for (j = 0; j < key; j++) {
			k = k * pt;
			k = k % n;
		}

		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}

	en[i] = -1;

	cout << "The encrypted string: ";

	for (i = 0; en[i] != -1; i++)
		cout << en[i];

	cout << endl;
}

/*
** Decrypt the string buffer using the generated key
*/
void decrypt() {
	long int pt, ct, key = d[0], k;
	i = 0;

	while (en[i] != -1) {
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++) {
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}

	m[i] = -1;

	cout << "Decrypted message: ";
	for (i = 0; m[i] != -1; i++)
		cout << m[i];

	cout << endl;
}