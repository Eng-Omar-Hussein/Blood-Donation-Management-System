class Donor {
private:
    string name, BloodType, mobile, id, age;
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
    void printData(vector<Donor>obj, int i);
    void printData_header();
    void printData_foater();
    void add_new(vector<Donor>&);
    void edit_data(vector<Donor>&);
    void update(vector<Donor>&);
    void overwrite_data(vector<Donor>&);
    void app_data(vector<Donor>&);
    void search(vector<Donor>);
    void search_recip(vector<Donor>, string);
    void Search_BloodType(vector<Donor>);
    void Search_no(vector<Donor>, int);
    bool check_BloodType(string);
    bool check_ID(string);
    bool check_mobile(string);
    bool check_age(string);
    int delete_element(vector<Donor>&);
    Donor(string, string, string, string, string);
    Donor();
};
