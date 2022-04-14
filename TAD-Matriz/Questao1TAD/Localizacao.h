#pragma once
class Localizacao
{
private:
    float latitude, longitude;

public:
    Localizacao(float lat, float lng);
    float getLatitude();
    float getLongitude();
    void setLatitude(float lat);
    void setLongitude(float lng);
    bool contidaNoIntervalo(Localizacao min, Localizacao max);
};