class Patient {
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
    void printData(vector<Patient>obj, int i);
    void add_new(vector<Patient>&, int*);
    void edit_data(vector<Patient>&, int*);
    void refrish(int*);
    void update(vector<Patient>&, int);
    void overwrite_data(vector<Patient>&, int);
    void app_data(vector<Patient>&, int);
    void search(vector<Patient>, int);
    void search_recip(vector<Patient>, int, string);
    void Search_BloodType(vector<Patient>, int);
    void Search_no(vector<Patient>, int, int);
    bool check_BloodType(string);
    bool check_ID(string);
    bool check_mobile(string);
    bool check_age(string);
    int delete_element(vector<Patient>&, int*);
    Patient(string, string, string, string, string);
    Patient();
};