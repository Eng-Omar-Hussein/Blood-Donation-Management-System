class password {
private:
    string x, y;
    string decrypt(string);
    string encrypt(string);
public:
    void set_password(string);
    bool check_password();
    bool check_legitpassword(string);
    void set_newpassword();
    password();
};