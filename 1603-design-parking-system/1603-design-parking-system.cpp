class ParkingSystem {
public:
    int b,m,s;
    ParkingSystem(int big, int medium, int small) 
    {
        b=big;
        m=medium;
        s=small;
        
    }
    
    bool addCar(int carType) 
    {
        switch(carType)
        {
            case 1:
                {
                if(b==0)
                    return false;
                else
                {
                    b--;
                    return true;
                }
                }
                 case 2:
                {
                if(m==0)
                    return false;
                else
                {
                    m--;
                    return true;
                }
                }
                 case 3:
                {
                if(s==0)
                    return false;
                else
                {
                    s--;
                    return true;
                }
                }
                
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */