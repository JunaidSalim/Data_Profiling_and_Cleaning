#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> null1(10, 0);
vector<int> null2(7, 0);
vector<int> Uniques(7, 0);
vector<string> Course;
vector<string> SID;
vector<string> Marks;
vector<string> Semester;
vector<string> Discipline;
vector<string> Year;
vector<string> Degree;

void Read_Data(vector<string>);
void outToNewFile();

static int sizeSL = 0;
static int LineSL = 0;
static int sizeCDL = 0;
static int LineCDL = 0;
static int sizeSP = 0;
static int LineSP = 0;
static int sizeCDP = 0;
static int LineCDP = 0;
static int invalid;

enum nullSL
{
    nullSID = 0,
    nullSName,
    nullFName,
    nullG,
    nullAd,
    nullDOB,
    nullRD,
    nullRS,
    nullDS,
    nullLD
};
enum nullCL
{
    nullCID = 0,
    nullD,
    nullSem,
    nullCors,
    nullMarks,
    nullDis,
    nullY
};

int readLines(const string &s)
{
    int Line = 0;
    ifstream in;
    in.open(s);
    in.ignore(100, '\n');
    while (!in.eof())
    {
        in.ignore(1000, '\n');
        Line++;
    }
    in.close();
    Line = Line - 1;
    return Line;
}

// code to find columns

int findColumns(const string &s)
{
    int column = 0;
    // code for automation.i.e column read.
    fstream in;
    in.open(s, ios::in);
    for (int i = 1; i >= 0; i++)
    {

        char c;
        in.get(c);
        if (c == ',')
        {
            column++;
        }
        if (c == '\n')
        {
            break;
        }

        in.seekg(i);
    }
    return column;
}

// find invalid values

// student class to store the students details
class Student
{

public:
    // functions to get the number of Males and Females
    static int getFcountL()
    {
        return fCountL;
    }
    static int getMcountL()
    {
        return mCountL;
    }
    static int getFcountP()
    {
        return fCountP;
    }
    static int getMcountP()
    {
        return mCountP;
    }

    string getDOB()
    {
        return DOB;
    }
    string getReg_Date()
    {
        return Reg_Date;
    }

    // update file
    void updatethefile()
    {

        string variation[6] = {"Peshawar", "PSH", "psh", "Psh", "peshawar", "PESHAWAR"};
        for (int i = 0; i < Address.length(); i++)
        {
            if (Address[Address.length() - i] == ' ')
            {
                bool flag = false;
                for (int j = 1; j < 6; j++)
                {
                    if (Address.substr(Address.length() - i + 1) == variation[j])
                    {
                        flag = true;
                    }
                }

                if (flag)
                {
                    Address = Address.substr(0, Address.length() - i + 1) + variation[0];
                    break;
                }
            }
        }
    }

    // Function to show the detail read from the file
    void showAll(fstream &out)
    {

        int columnWidths[] = {10, 30, 30, 5, 57, 12, 12, 10, 12, 20};

        // Output the data in columns
        out << std::left << std::setw(columnWidths[0]) << SID << ","
            << std::setw(columnWidths[1]) << St_Name << ","
            << std::setw(columnWidths[2]) << Father_Name << ",";

        if (!Gender)
        {
            out << std::setw(columnWidths[3]) << "M ,";
        }
        else
        {
            out << std::setw(columnWidths[3]) << "F ,";
        }

        out << std::setw(columnWidths[4]) << Address << ","
            << std::setw(columnWidths[5]) << DOB << ","
            << std::setw(columnWidths[6]) << Reg_Date << ","
            << std::setw(columnWidths[7]) << Reg_Status << ","
            << std::setw(columnWidths[8]) << Degree_Status << ","
            << std::setw(columnWidths[9]) << Last_Degree << std::endl;
    }

    // function to
    vector<int> read_L_StudentData(fstream &file)
    {

        getline(file, checkSID, ',');
        if (checkSID.empty())
        {
            SID = -1;
            ++null1[nullSL::nullSID];
        }
        else
        {
            SID = stoi(checkSID);
        }

        getline(file, St_Name, ',');
        if (St_Name.empty())
        {
            ++null1[nullSL::nullSName];
        }

        getline(file, Father_Name, ',');
        if (Father_Name.empty())
        {
            ++null1[nullSL::nullFName];
        }

        getline(file, checkGender, ',');
        if (checkGender.empty())
        {
            Gender = 1;
            ++null1[nullSL::nullG];
            mCountL++;
        }
        else
        {
            Gender = stoi(checkGender);
            if (!Gender)
            {
                mCountL++;
            }
            else
            {
                fCountL++;
            }
        }

        getline(file, Address, ',');
        if (Address.empty())
        {
            ++null1[nullSL::nullAd];
        }

        getline(file, DOB, ',');
        if (DOB.empty())
        {
            ++null1[nullSL::nullDOB];
        }

        getline(file, Reg_Date, ',');
        if (Reg_Date.empty())
        {
            ++null1[nullSL::nullRD];
        }

        file >> Reg_Status;
        if (Reg_Status == '\0')
        {
            ++null1[nullSL::nullRS];
        }
        file.ignore(1);

        file >> Degree_Status;
        if (Degree_Status == '\0')
        {
            ++null1[nullSL::nullDS];
        }
        file.ignore(1);

        getline(file, Last_Degree);
        if (Last_Degree.empty())
        {
            ++null1[nullSL::nullLD];
        }
        return null1;
    }

    vector<int> read_P_StudentData(fstream &file, int SP)
    {

        fstream in;
        int Lines = readLines("Data/female_names.txt");
        in.open("Data/female_names.txt", ios::in);
        vector<string> N[Lines];

        getline(file, checkSID, ',');
        if (checkSID.empty())
        {
            SID = -1;
            ++null1[nullSL::nullSID];
        }
        else
        {
            SID = stoi(checkSID);
        }

        getline(file, St_Name, ',');
        if (St_Name.empty())
        {
            ++null1[nullSL::nullSName];
        }

        getline(file, Father_Name, ',');
        if (Father_Name.empty())
        {
            ++null1[nullSL::nullFName];
        }
        string s = St_Name.substr(0, St_Name.find(' '));

        for (int i = 0; i < Lines; i++)
        {
            string d;
            in >> d;

            if (s == d)
            {
                Gender = 1;
                fCountP++;
                break;
            }
            else
            {
                Gender = 0;
            }
        }

        mCountP = SP - fCountP;
        getline(file, Address, ',');
        if (Address.empty())
        {
            ++null1[nullSL::nullAd];
        }

        getline(file, DOB, ',');
        if (DOB.empty())
        {
            ++null1[nullSL::nullDOB];
        }

        getline(file, Last_Degree, ',');
        if (Last_Degree.empty())
        {
            ++null1[nullSL::nullLD];
        }

        getline(file, Reg_Date, ',');
        if (Reg_Date.empty())
        {
            ++null1[nullSL::nullRD];
        }
        file >> Reg_Status;
        if (Reg_Status == '\0')
        {
            ++null1[nullSL::nullRS];
        }

        file.ignore(1);

        file >> Degree_Status;
        if (Degree_Status == '\0')
        {
            ++null1[nullSL::nullDS];
        }
        return null1;
    }

    // function to validate DOB and Reg_Date
    bool checkvaliddate(string str, int Regyr)
    {
        if (Regyr % 4 != 0)
        {
            size_t hypenpos = str.find("-");

            int position = static_cast<int>(hypenpos);
            int day = stoi(str.substr(0, position));
            string bstr = str.substr(position + 1, 3);

            if (bstr == "Feb" && day >= 29)
            {
                return true;
            }
            if (bstr != "Feb" && day > 31)
            {
                return true;
            }
        }

        if (Regyr % 4 == 0)
        {
            size_t hypenpos = str.find("-");
            int position = static_cast<int>(hypenpos);

            int day = stoi(str.substr(0, position));

            string bstr = str.substr(position + 1, 3);

            if (bstr == "Feb" && day > 29)
            {
                return true;
            }
            if (bstr != "Feb" && day > 31)
            {
                return true;
            }
        }
        return false;
    }
    // invalid

    void Invalid()
    {

        int DObyr, Regyr;
        string my_str1 = DOB;
        string my_str2 = Reg_Date;
        if ((my_str1.empty() || my_str2.empty()))
            ;
        else
        {
            int num_chars = 2; // Get the last 5 characters
            string last_chars1 = my_str1.substr(my_str1.length() - num_chars);
            string last_chars2 = my_str2.substr(my_str2.length() - num_chars);
            DObyr = stoi(last_chars1);
            Regyr = stoi(last_chars2);
            if (checkvaliddate(Reg_Date, Regyr))
                invalid++;
            if (checkvaliddate(DOB, DObyr))
                invalid++;
            if (Regyr < 10)
            {
                Regyr += 100;
            }

            if (Regyr - DObyr < 18)
            {
                invalid++;
            }
        }
        if (my_str1.empty())
            if (checkvaliddate(Reg_Date, Regyr))
                invalid++;
        if (my_str2.empty())
            if (checkvaliddate(DOB, DObyr))
                invalid++;
    }

protected:
    // Helper function to standardize a name

    string checkSID;
    int SID;
    string St_Name;
    string Father_Name;
    string checkGender;
    int Gender;
    string Address;
    string DOB;
    string Reg_Date;
    char Reg_Status;
    char Degree_Status;
    string Last_Degree;
    static int fCountL, mCountL, fCountP, mCountP;
    string file_Name;
};

// class for storing Course detail of student
class CourseDetails : public Student
{
public:
    int getSID() const
    {
        return CID;
    }

    string getSemester() const
    {
        return Semester;
    }

    // find invalids in score
    static int getInvalid()
    {
        return invalid;
    }

    vector<int> read_L_Course(fstream &file)
    {

        // read ID from the file
        getline(file, checkGender, ',');
        if (checkGender.empty())
        {
            CID = -1;
            ++null2[nullCL::nullCID];
        }
        else
        {
            try
            {
                CID = stoi(checkGender);
            }
            catch (const std::exception &e)
            {

                CID = 0;
                cout << "Error";
            }
        }

        // read the Degree type from the file
        getline(file, Degree, ',');
        if (Degree.empty())
        {
            ++null2[nullCL::nullD];
        }

        // read the semester from the file
        getline(file, Semester, ',');
        if (Semester.empty())
        {
            ++null2[nullCL::nullSem];
        }

        // read the course from the file
        getline(file, course, ',');
        if (course.empty())
        {
            ++null2[nullCL::nullCors];
        }

        // read the marks obtained from the file
        getline(file, checkSID, ',');
        if (checkSID.empty())
        {
            Marks = 0;
            ++null2[nullCL::nullMarks];
        }
        else
        {
            try
            {
                Marks = stoi(checkSID);
            }
            catch (exception &e)
            {
                Marks = 0;
                cout << "Yes";
            }
        }

        // read the discipling of the student from the file
        getline(file, Discipline);
        if (Discipline.empty())
        {
            ++null2[nullCL::nullDis];
        }

        return null2;
    }

    vector<int> read_P_Course(fstream &file)
    {

        getline(file, checkGender, ',');
        if (checkGender.empty())
        {
            CID = -1;
            ++null2[nullCL::nullCID];
        }
        else
        {
            try
            {
                CID = stoi(checkGender);
            }
            catch (const exception &e)
            {
                CID = 0;
                cout << "Error";
            }
            //
        }
        //        // read the course from the file
        getline(file, course, ',');
        if (course.empty())
        {
            ++null2[nullCL::nullCors];
        }

        getline(file, CheckMarks, ',');
        if (CheckMarks.empty())
        {
            Marks = 0;
            ++null2[nullCL::nullMarks];
        }
        else
        {
            try
            {
                Marks = std::stoi(CheckMarks);
            }
            catch (const std::exception &e)
            {

                Marks = 0;
                std::cout << "Error";
            }
        }

        // read the discipling of the student from the file
        getline(file, Discipline, ',');
        if (Discipline.empty())
        {
            ++null2[nullCL::nullDis];
        }

        // read the semester from the file
        getline(file, Semester, ',');
        if (Semester.empty())
        {
            ++null2[nullCL::nullSem];
        }

        getline(file, checkGender);
        if (checkGender.empty())
        {
            year = 1994;
            ++null2[nullCL::nullY];
        }
        else
        {
            try
            {
                year = stoi(checkGender);
            }
            catch (const exception &e)
            {
                year = 0;
                cout << "Error";
            }
        }
        return null2;
    }

    void showAll_L(fstream &out)
    {
        out << endl
            << CID << " , " << Degree << " , " << Semester << " , " << course << " , " << Marks << " , " << Discipline;
    }

    void showAll_P(fstream &out)
    {
        out << endl
            << CID << " , " << course
            << " , " << Marks << " , " << Discipline << " , " << Semester << " , " << year;
    }

    int semyr()
    {
        if (Semester.length() == 5 || Semester.length() == 8)
        {
            int semyr = stoi(Semester.substr(Semester.length() - 2));
            return semyr;
        }
        if (Semester.empty())
            return 0;
        else
            return year;
    }

    void invalidscore()
    {
        int invalid = 0;

        if (Marks > 100 || Marks < 0)
        {
            invalid++;
        }
    }

    // Unique values
    vector<int> Unique_Courses()
    {

        string S;

        bool flag = true;
        for (const auto &j : ::SID)
        {
            S = to_string(CID);
            if (S == j)
                flag = false;
        }
        if (flag)
        {
            ::SID.push_back(S);
            ++Uniques[nullCL::nullCID];
        }

        flag = true;
        for (const auto &j : ::Degree)
        {

            if (Degree == j)
                flag = false;
        }
        if (flag)
        {
            ::Degree.push_back(Degree);
            ++Uniques[nullCL::nullD];
        }

        flag = true;
        S = to_string(Marks);
        for (const auto &Mark : ::Marks)
        {

            if (S == Mark)
                flag = false;
        }
        if (flag)
        {

            ::Marks.push_back(S);
            ++Uniques[nullCL::nullMarks];
        }

        flag = true;
        for (const auto &j : ::Semester)
        {

            if (Semester == j)
                flag = false;
        }
        if (flag)
        {
            ::Semester.push_back(Semester);
            ++Uniques[nullCL::nullSem];
        }

        flag = true;
        for (const auto &j : ::Course)
        {
            if (course == j)
                flag = false;
        }
        if (flag)
        {
            ::Course.push_back(course);
            ++Uniques[nullCL::nullCors];
        }

        flag = true;
        for (const auto &j : ::Discipline)
        {
            if (Discipline == j)
                flag = false;
        }
        if (flag)
        {
            ::Discipline.push_back(Discipline);
            ++Uniques[nullCL::nullDis];
        }

        flag = true;
        for (const auto &j : Year)
        {
            S = to_string(year);
            if (S == j)
                flag = false;
        }
        if (flag)
        {
            Year.push_back(S);
            ++Uniques[nullCL::nullDis];
        }
        flag = true;

        return Uniques;
    }

private:
    // variables of the class as private members
    int CID;
    string CheckMarks;
    string Degree;
    string Semester;
    string course;
    int Marks;
    string Discipline;
    int year;
};

int Coursesmorethanfive(vector<CourseDetails> C)
{
    vector<int> Morethan5(2, 0);
    vector<string> mysemester;
    vector<int> myyear;
    vector<int> storerelatedid;
    vector<int> IDs;
    int morethan5 = 0;
    int n_of_s = 0;
    int n_of_sem = 0;

    for (int i = 0; i < C.size(); i++)
    {

        bool isuniquesemester = true;
        bool isuniquestudent = true;
        for (int j = 0; j < mysemester.size(); j++)
        {
            if (!C[i].getSemester().empty())
            {
                if (C[i].getSemester() == mysemester[j] && C[i].semyr() == myyear[j])
                {
                    if (C[i].getSID() - storerelatedid[j] >= 300)
                    {
                        mysemester.clear();
                        myyear.clear();
                        storerelatedid.clear();
                        isuniquesemester = true;
                        break;
                    }
                    else
                        isuniquesemester = false;
                }
            }
            else
            {
                isuniquesemester = false;
            }
        }
        bool semesterfound = false;
        for (int l = 0; l < IDs.size(); l++)
        {
            if (C[i].getSID() == IDs[l])
            {
                semesterfound = true;
            }
        }
        if (semesterfound)
        {
            isuniquestudent = false;
        }

        if (isuniquesemester)
        {
            mysemester.push_back(C[i].getSemester());
            myyear.push_back(C[i].semyr());
            storerelatedid.push_back(C[i].getSID());
        }

        int count = 0;
        if (isuniquestudent)
        {
            n_of_s++;
            IDs.push_back(C[i].getSID());

            for (int k = i + 1; k < C.size(); k++)
            {
                if (C[i].getSID() == C[k].getSID())
                {
                    count++;
                }
                else
                    break;
            }
            if (count > 4)
            {
                morethan5++;
            }
        }
    }

    return morethan5;
}

int Student::fCountL = 0;
int Student::mCountL = 0;
int Student::fCountP = 0;
int Student::mCountP = 0;
vector<Student> SL(0);
vector<CourseDetails> CL(0);
vector<Student> SP(0);
vector<CourseDetails> CP(0);

int main()
{

    vector<string> filename = {"Data/Lhr_Detail_94.txt", "Data/Lhr_Detail_95.txt", "Data/Lhr_Detail_96.txt", "Data/Lhr_Detail_97.txt", "Data/Lhr_Detail_98.txt", "Data/Lhr_Detail_99.txt", "Data/Lhr_Detail_100.txt", "Data/Lhr_Detail_101.txt", "Data/Lhr_Detail_102.txt", "Data/Lhr_Detail_103.txt", "Data/Lhr_Detail_104.txt", "Data/Lhr_Student_94.txt", "Data/Lhr_Student_95.txt", "Data/Lhr_Student_96.txt", "Data/Lhr_Student_97.txt", "Data/Lhr_Student_98.txt", "Data/Lhr_Student_99.txt", "Data/Lhr_Student_100.txt", "Data/Lhr_Student_101.txt", "Data/Lhr_Student_102.txt", "Data/Lhr_Student_103.txt", "Data/Lhr_Student_104.txt", "Data/Lhr_Detail_MS_101.txt", "Data/Lhr_Detail_MS_102.txt", "Data/Lhr_Detail_MS_103.txt", "Data/Lhr_Detail_MS_104.txt", "Data/Lhr_Student_MS_101.txt", "Data/Lhr_Student_MS_102.txt", "Data/Lhr_Student_MS_103.txt", "Data/Lhr_Student_MS_104.txt", "Data/Transfer.txt", "Data/BS_P_94_Reg.txt", "Data/BS_P_95_Reg.txt", "Data/BS_P_96_Reg.txt", "Data/BS_P_97_Reg.txt", "Data/BS_P_98_Reg.txt", "Data/BS_P_99_Reg.txt", "Data/BS_P_100_Reg.txt", "Data/BS_P_101_Reg.txt", "Data/BS_P_102_Reg.txt", "Data/BS_P_103_Reg.txt", "Data/BS_P_104_Reg.txt", "Data/MS_P_101_Reg.txt", "Data/MS_P_102_Reg.txt", "Data/MS_P_103_Reg.txt", "Data/MS_P_104_Reg.txt", "Data/BS_P_94_Student.txt", "Data/BS_P_95_Student.txt", "Data/BS_P_96_Student.txt", "Data/BS_P_97_Student.txt", "Data/BS_P_98_Student.txt", "Data/BS_P_99_Student.txt", "Data/BS_P_100_Student.txt", "Data/BS_P_101_Student.txt", "Data/BS_P_102_Student.txt", "Data/BS_P_103_Student.txt", "Data/BS_P_104_Student.txt", "Data/MS_P_101_Student.txt", "Data/MS_P_102_Student.txt", "Data/MS_P_103_Student.txt", "Data/MS_P_104_Student.txt"};

    Read_Data(filename);

    outToNewFile();
    cout << endl;
    cout << "***Number of Nulls in Lahore and Peshawar Student Data*** ";
    cout << endl
         << "Number of Null SID: " << null1[nullSL::nullSID];
    cout << endl
         << "Number of Null Student Name: " << null1[nullSL::nullSName];
    cout << endl
         << "Number of Null Father Name: " << null1[nullSL::nullFName];
    cout << endl
         << "Number of Null Gender: " << null1[nullSL::nullG];
    cout << endl
         << "Number of Null DOB: " << null1[nullSL::nullDOB];
    cout << endl
         << "Number of Null Reg_Date: " << null1[nullSL::nullRD];
    cout << endl
         << "Number of Null Reg_Status: " << null1[nullSL::nullRS];
    cout << endl
         << "Number of Null Degree_Status: " << null1[nullSL::nullDS];
    cout << endl
         << "Number of Null Last_Degree: " << null1[nullSL::nullLD];

    int Line;
    Line = readLines("Output_Student_Data.txt") - 1;

    cout << endl;
    cout << endl
         << "Number of Average Students Per Year: " << Line / 11;

    cout << endl
         << "***Number of Nulls in Lahore and Peshawar Student Data*** ";
    cout << endl
         << "Number of Null SID: " << null2[nullCL::nullCID];
    cout << endl
         << "Number of Null in Degree: " << null2[nullCL::nullD];
    cout << endl
         << "Number of Null Semester: " << null2[nullCL::nullSem];
    cout << endl
         << "Number of Null Course: " << null2[nullCL::nullCors];
    cout << endl
         << "Number of Null Marks: " << null2[nullCL::nullMarks];
    cout << endl
         << "Number of Null Discipline: " << null2[nullCL::nullDis];
    cout << endl
         << "Number of Null Year: " << null2[nullCL::nullY];

    cout << endl
         << "Ratio Male Students to Female Students: " << Student::getMcountL() + Student::getMcountP() << " : " << Student::getFcountL() + Student::getFcountP();

    cout << endl
         << "Total Number of Students who have taken more than 5 Courses: " << Coursesmorethanfive(CL) + Coursesmorethanfive(CP);
    cout << endl
         << "Total Number of Unique IDs vs Total Students Are: " << Uniques[nullCL::nullCID] << " vs " << Line;

    cout << endl;
    cout << endl
         << "***Number of Uniques in Lahore and Peshawar Student Data*** ";
    cout << endl
         << "Number of Uniques SID: " << Uniques[nullCL::nullCID];
    cout << endl
         << "Number of Uniques in Degree: " << Uniques[nullCL::nullD];
    cout << endl
         << "Number of Unique Semester: " << Uniques[nullCL::nullSem];
    cout << endl
         << "Number of Unique Course: " << Uniques[nullCL::nullCors];
    cout << endl
         << "Number of Unique Marks: " << Uniques[nullCL::nullMarks];
    cout << endl
         << "Number of Unique Discipline: " << Uniques[nullCL::nullDis];
    cout << endl
         << "Number of Unique Year: " << Uniques[nullCL::nullY];
    cout << endl
         << "Invalid Are: " << invalid;
    cout << endl
         << "Average number of student per semester are: " << Line * 8 / 208;
}

// function which reads data from the file
void Read_Data(vector<string> filename)
{
    for (int i = 0; i < filename.size(); i++)
    {

        fstream in;
        fstream inn;
        string line;

        int column = findColumns(filename[i]);

        if (column == 9)
        {

            LineSL += readLines(filename[i]);
            SL.resize(LineSL);
            in.open(filename[i], ios::in);
            in.ignore(100, '\n');

            inn.open(filename[i], ios::in);

            for (; sizeSL < LineSL; sizeSL++)
            {
                getline(inn, line);
                if (line.empty())
                {
                    continue; // Skip empty lines
                }
                null1 = SL[sizeSL].read_L_StudentData(in);
            }
            inn.close();
            in.close();
        }
        else if (column == 5)
        {
            if (i > 30 && i < 46)
            {
                LineCDP += readLines(filename[i]);
                CP.resize(LineCDP);
                in.open(filename[i], ios::in);
                inn.open(filename[i], ios::in);
                in.ignore(100, '\n');

                for (; sizeCDP < LineCDP; sizeCDP++)
                {
                    getline(inn, line);
                    if (line.empty())
                    {
                        continue;
                    }
                    null2 = CP[sizeCDP].read_P_Course(in);
                }
                inn.close();
                in.close();
            }
            else
            {
                LineCDL += readLines(filename[i]);
                CL.resize(LineCDL);
                in.open(filename[i], ios::in);
                in.ignore(100, '\n');
                inn.open(filename[i], ios::in);

                for (; sizeCDL < LineCDL; sizeCDL++)
                {
                    getline(inn, line);
                    if (line.empty())
                    {
                        continue;
                    }
                    null2 = CL[sizeCDL].read_L_Course(in);
                }
                inn.close();
                in.close();
            }
        }
        else if (column == 8)
        {

            LineSP += readLines(filename[i]);
            SP.resize(LineSP);
            in.open(filename[i], ios::in);
            in.ignore(100, '\n');
            inn.open(filename[i], ios::in);

            for (; sizeSP < LineSP; sizeSP++)
            {
                getline(inn, line);
                if (line.empty())
                {
                    continue;
                }
                null1 = SP[sizeSP].read_P_StudentData(in, LineSP);
            }

            for (int j = 0; j < LineSP; j++)
            {
                SP[j].updatethefile();
            }
            inn.close();
            in.close();
        }
    }
}

// out to file to new file

void outToNewFile()
{
    fstream out1;
    out1.open("Output_Student_Data.txt", ios::out);
    out1 << "SID ," << setw(14) << "St_Name ," << setw(34) << "Father_Name ," << setw(20) << "Gender," << setw(10)
         << "Address,"
         << setw(59) << "Date of Birth," << setw(12) << "Reg Date," << setw(11) << "Reg_Status," << setw(14)
         << "Degree_Status," << setw(12) << "Last_Degree," << endl;

    for (int i = 0; i < LineSL; i++)
    {
        SL[i].showAll(out1);
        SL[i].Invalid();
    }
    for (int i = 0; i < LineSP; i++)
    {
        SP[i].showAll(out1);
        SP[i].Invalid();
    }

    out1.close();
    fstream out2;
    out2.open("Output_Course_Data.txt", ios::out);
    out2 << "SID,Degree,Semester,Course,Marks,Discipline";
    for (int i = 0; i < LineCDL; i++)
    {
        CL[i].showAll_L(out2);
        Uniques = CL[i].Unique_Courses();
        CL[i].invalidscore();
    }

    for (int i = 0; i < LineCDP; i++)
    {
        CP[i].showAll_P(out2);
        Uniques = CP[i].Unique_Courses();
        CP[i].invalidscore();
    }
    out2.close();
}