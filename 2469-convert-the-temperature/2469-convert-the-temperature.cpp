class Solution
{
    public:
    double roundWithPrecision(double value, int precision)
    {
        double factor = pow(10, precision);
        return round(value *factor) / factor;
    }
    vector<double> convertTemperature(double celsius)
    {
        double kelvin = celsius + 273.15;
        double F = celsius *1.80 + 32.00;
        vector<double> temperatures = { roundWithPrecision(kelvin, 5),roundWithPrecision(F, 5)};
        return temperatures;
    }
};