class Donor {
private:
    string name, BloodType, mobile, age, id;
public:
    string getName();
    string getBloodType();
    string getMobile();
    string getAge();
    string getID();
    void setName(string);
    void setBloodType(string);
    void setAge(string);
    void setMobile(string);
    void setID(string);
    void readData();
    void printData(vector<Donor>, int);
    void printData_header();
    void printData_foater();
    void add_new(vector<Donor>&, int*);
    void edit_data(vector<Donor>&, int*);
    void refrish(int*);
    void update(vector<Donor>&, int);
    void overwrite_data(vector<Donor>&, int);
    void app_data(vector<Donor>&, int);
    void search(vector<Donor>, int);
    void search_recip(vector<Donor>, int, string);
    void Search_BloodType(vector<Donor>, int);
    void Search_no(vector<Donor>, int, int);
    bool check_BloodType(string);
    bool check_Duplicate_ID(string, vector<Donor>, int);
    bool check_ID(string, vector<Donor>, int);
    bool check_mobile(string);
    bool check_age(string);
    int delete_element(vector<Donor>&, int*);
    Donor(string, string, string, string, string);
    Donor();
};
