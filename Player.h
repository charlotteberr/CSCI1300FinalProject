#include <string>

using namespace std;

class Player{
    private:
        string playerName;
        int experience;
        int accuracy;
        int efficieny;
        int insight;
        int discoveryPoints;
        int advisor;
        int pathType;
        int lane;
    public:
        Player(); // default constructor
        Player(string n, int exp, int acc, int eff, int ins, int dp, int adv, int pt, int l); // parameterized constructor

        string getName();
        int getExperience();
        int getAccuracy();
        int getEfficiency();
        int getInsight();
        int getDiscoveryPts();
        int getAdvisor();
        int getPathType();
        int getLane();

        void setName(string n);
        void setExperience(int exp);
        int setAccuracy(int acc);
        int setEfficiency(int eff);
        int setInsight(int ins);
        int setDiscoveryPts(int dp);
        int setAdvisor(int adv);
        int setPathType(int pt);
        int setLane(int l);
};