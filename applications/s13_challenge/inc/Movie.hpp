#include <string>

class Movie {
private:
    std::string name;
    int rate;   // x/10
    int count;  // watched counter
public:
    Movie(const std::string& name, int rate, int count);

    std::string get_name() {
        return name;
    } 
    int get_rate(){
        return rate;
    }
    int get_count() {
        return count;
    }

    void set_count(int cnt) {
        count = cnt;
    }
};