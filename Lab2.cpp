#include <iostream>
#include <cmath>

class Vector3D {
public:
    double x, y, z;

    // Constructor
    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    // Operatii de adunare si scadere a vectorilor
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    // Produs scalar a doi vectori
    double operator*(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Lungimea vectorului
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Functie prietena pentru calculul cosinusului unghiului intre vectori
    friend double cosineAngle(const Vector3D& v1, const Vector3D& v2);
};

// Functia prietena pentru calculul cosinusului unghiului intre vectori
double cosineAngle(const Vector3D& v1, const Vector3D& v2) {
    double dotProduct = v1 * v2;
    double magnitudeProduct = v1.length() * v2.length();

    if (magnitudeProduct == 0) {
        // Evitarea împărțirii la zero
        return 0.0;
    }

    return dotProduct / magnitudeProduct;
}

int main() {
    double v1x, v1y, v1z, v2x, v2y, v2z;
    std::cout << "Introdu cifrele pentru v1\n";
    std::cout << "x:";
    std::cin >> v1x;
    std::cout << "y:";
    std::cin >> v1y;
    std::cout << "z:";
    std::cin >> v1z;
    
    std::cout << "Introdu cifrele pentru v2\n";
    std::cout << "x:";
    std::cin >> v2x;
    std::cout << "y:";
    std::cin >> v2y;
    std::cout << "z:";
    std::cin >> v2z;
    
    // Vectori tridimensionali
    Vector3D v1(v1x, v1y, v1z);
    Vector3D v2(v2x, v2y, v2z);

    // Adunare si scadere
    Vector3D sum = v1 + v2;
    Vector3D difference = v1 - v2;

    // Produs scalar
    double dotProduct = v1 * v2;

    // Lungimi si cosinusul unghiului intre vectori
    double v1Length = v1.length();
    double v2Length = v2.length();
    double cosine = cosineAngle(v1, v2);

    
    std::cout << "Suma: (" << sum.x << ", " << sum.y << ", " << sum.z << ")\n";
    std::cout << "Diferenta: (" << difference.x << ", " << difference.y << ", " << difference.z << ")\n";
    std::cout << "Produsul scalar: " << dotProduct << "\n";
    std::cout << "Lungimea lui v1: " << v1Length << "\n";
    std::cout << "Lungimea lui v2: " << v2Length << "\n";
    std::cout << "Cosinusul unghiului: " << cosine << "\n";

    return 0;
}
