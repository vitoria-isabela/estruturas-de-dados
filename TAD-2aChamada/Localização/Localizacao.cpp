#include "Localizacao.h"
#include <iostream>
using namespace std;

Localizacao::Localizacao(float lat, float lng)
{
    setLatitude(lat);
    setLongitude(lng);
}

float Localizacao::getLatitude()
{
    return latitude;
}

float Localizacao::getLongitude()
{
    return longitude;
}

void Localizacao::setLatitude(float latitude)
{
    if (latitude < -90 || latitude > 90)
    {
        cout << "Coordenadas invalidas!" << endl;
        exit(1);
    }
    this->latitude = latitude;
}

void Localizacao::setLongitude(float longitude)
{
    if (longitude < -180 || longitude > 180)
    {
        cout << "Coordenadas invalidas!" << endl;
        exit(1);
    }
    this->longitude = longitude;
}

bool Localizacao::contidaNoIntervalo(Localizacao* min, Localizacao* max)
{
    if (latitude >= (*min).latitude && latitude <= (*max).latitude &&
        longitude >= (*min).longitude && longitude <= (*max).longitude)
        return true;
    else
        return false;
}