#include <iostream>
#include <vector>

void sitoErastotenesa(int n) {
    std::vector<bool> prime(n + 1, true); // Tablica przechowuj¹ca informacje o liczbach pierwszych

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    std::vector<int> primeNumbers; // Wektor przechowuj¹cy liczby pierwsze

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primeNumbers.push_back(p);
        }
    }

    if (n > 1000) {
        // Dla du¿ych wartoœci koñcowych wypisz trzy ostatnie liczby pierwsze
        int size = primeNumbers.size();
        if (size >= 3) {
            std::cout << "Trzy ostatnie liczby pierwsze: ";
            for (int i = size - 3; i < size; i++) {
                std::cout << primeNumbers[i] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        // Wypisz wszystkie liczby pierwsze
        std::cout << "Liczby pierwsze: ";
        for (int num : primeNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Podaj koncowa wartosc: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Brak liczb pierwszych dla podanej wartosci." << std::endl;
    } else {
        sitoErastotenesa(n);
    }

    return 0;
}
