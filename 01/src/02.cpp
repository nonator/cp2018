#include <cmath>
#include <cstdio>
#include <random>

// Aufgabenteil a)
void a(int p) {
    printf("Schätzung des Kugelvolumens:\n");
    printf("============================\n");

    // Initialisierung von
    // Anzahl Iterationen N
    // Anzahl der Punkte im Kresi n
    // Radius der Kugel radius_sq
    // Zufallszahlen x, y, z
    const int N = pow(10, p);
    int n = 0;
    double radius_sq;
    double x, y, z;

    // Initialisierung des Random Number Generators
    // nach Anleitung von Übungsblatt 00
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_real_distribution<> dist(0, 1);

    for (int i = 0; i < N; i++) {
        x = dist(rng);
        y = dist(rng);
        z = dist(rng);
        // Berechnung des Radius
        radius_sq = pow(x, 2) + pow(y, 2) + pow(z, 2);
        if (radius_sq < 1) {
            // Zähle, wie viele Zahlentupel innerhalb des Kugelradius liegen
            n++;
        }
    }

    printf("N: %d, ", N);
    printf("n: %d\n", n);

    // Schätze Pi und das Kugelvolumen
    const double pi_est = 6 * (static_cast<double>(n) / static_cast<double>(N));
    const double Vol_est = (4./3.) * pi_est;

    const double pi = 3.14159;
    const double Vol = (4./3.) * pi;

    const double Vol_rel_error = (Vol_est - Vol) / Vol * 100;

    printf("Pi estimated: %f\n", pi_est);
    printf("Volumen estimated: %f\n", Vol_est);
    printf("Relativer Fehler Volumen: %f%%\n", Vol_rel_error);
}

// Aufgabenteil b)
void b() {
    const double pi = 3.14159;
    double c = 1 / sqrt(pi);
    double func = 0;
    for (int i = 0; i < static_cast<int>(1e2); i++){
        func = c * exp(- i * i);
    }
}

int main() {
    a(7);
    b();
    return 0;
}

