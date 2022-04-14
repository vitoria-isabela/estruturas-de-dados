#include <iostream>
#include <cstdlib>
#include "Localizacao.h"

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

void Localizacao::setLatitude(float lat)
{
    if (lat < -90 || lat > 90)
    {
        cout << "Coordenadas invalidas!" << endl;
        exit(1);
    }
    latitude = lat;
}

void Localizacao::setLongitude(float lng)
{
    if (lng < -180 || lng > 180)
    {
        cout << "Coordenadas invalidas!" << endl;
        exit(1);
    }
    longitude = lng;
}

bool Localizacao::contidaNoIntervalo(Localizacao min, Localizacao max)
{
    if (latitude >= min.latitude && latitude <= max.latitude &&
        longitude >= min.longitude && longitude <= max.longitude)
        return true;
    else
        return false;
}