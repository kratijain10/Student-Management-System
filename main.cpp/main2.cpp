#include <string>
#include <iostream>

using namespace std;

struct student
{
   string first_name;
   string last_name;
   int roll_number;
   double cgpa;
   int course_id[10];
} students[110];

int number_of_students = 0;

void addStudentDetails()
{

   cout << "\nEnter the new student details\n";
   cout << "------------------------------------------------------------------------------" << endl;
   cout << "Enter the Roll Number of the student\n";
   int roll_no;
   cin >> roll_no;

   for (int i = 0; i < number_of_students; i++)
   {
      if (students[i].roll_number == roll_no)
      {
         cout << " Student with the given roll number already exists in the database\n";
         return;
      }
   }

   cout << "Enter the first name of the student : ";
   cin >> students[number_of_students].first_name;

   cout << "\nEnter the last name of the student : ";
   cin >> students[number_of_students].last_name;

   students[number_of_students].roll_number = roll_no;

   cout << "\nEnter the CGPA of the student : ";
   cin >> students[number_of_students].cgpa;

   cout << "\nEnter the course ID (Number) of course in which the student is enrolled : ";
   for (int i = 0; i < 1; i++)
   {

      cin >> students[number_of_students].course_id[i];
   }

   number_of_students++;
}

void findTotalStudents()
{
   cout << "\nThe total number Students are " << number_of_students << "\n";
   cout << "You can have maximum of 110 students in the database\n";
}

// void show_data(int searchkey) // Function for showing data on the screen.
// {
//    int i = searchkey;
//    cout << students[i].roll_number << "\t";
//    cout << students[i].first_name << "\t";
//    cout << students[i].last_name << "\t";
//    cout << students[i].cgpa << "\t";
//    cout << students[i].course_id[0] << "," << students[i].course_id[1];
// }

// void studentsList()
// {

//    cout << endl;
//    cout << "--------------------------------------------------------------------------------" << endl;
//    cout << "---------------------------Student record Table---------------------------------" << endl;
//    cout << "--------------------------------------------------------------------------------" << endl;
//    cout << "Roll No\t"
//         << "First Name\t"
//         << "Last Name\t"
//         << "CGPA\t"
//         << "Course ID";
//    cout << "--------------------------------------------------------------------------------" << endl;

//    int i=0;
//    while(students[i].roll_number != NULL){
//       show_data(i);
//       i++;
//    }
// }

void findStudentByRollNumber()
{
   int roll_no;
   cout << "\nEnter the Roll Number of the student : ";
   cin >> roll_no;

   bool found = false;

   for (int i = 0; i < number_of_students; i++)
   {
      if (roll_no == students[i].roll_number)
      {
         found = true;

         cout << "The Students Details are:\n";

         cout << "The First name is " << students[i].first_name << "\n";
         cout << "The Last name is " << students[i].last_name << "\n";
         cout << "The CGPA is " << students[i].cgpa << "\n";
         cout << "The course ID of each course\n";

         for (int j = 0; j < 5; j++)
         {
            cout << students[i].course_id[j] << " ";
         }

         break;
      }
   }

   if (!found)
      cout << "No such student with the given roll number\n";
}

void findStudentByFirstName()
{
   string firstName;
   cout << "\nEnter the first name of the student : ";
   cin >> firstName;

   bool found = false;

   for (int i = 0; i < number_of_students; i++)
   {
      if (firstName == students[i].first_name)
      {
         found = true;

         cout << "\nThe Students Details are\n";

         cout << "The First name is " << students[i].first_name << "\n";
         cout << "The Last name is " << students[i].last_name << "\n";
         cout << "The CGPA is " << students[i].cgpa << "\n";
         cout << "The course ID of each course\n";

         for (int j = 0; j < 5; j++)
         {
            cout << students[i].course_id[j] << " ";
         }

         cout << "\n";
      }
   }

   if (!found)
      cout << "No such student with the given first name\n";
}

void findStudentByCourseId()
{
   int id;
   cout << "\nEnter the course id : ";
   cin >> id;

   bool found = false;

   for (int i = 0; i < number_of_students; i++)
   {

      for (int j = 0; j < 5; j++)
      {

         if (id == students[i].course_id[j])
         {

            found = true;
            cout << "\nThe Students Details are\n";

            cout << "The First name is " << students[i].first_name << "\n";
            cout << "The Last name is " << students[i].last_name << "\n";
            cout << "The CGPA is " << students[i].cgpa << "\n";
            cout << "\n";
         }
      }
   }

   if (!found)
      cout << "\nNo such students with the given course id\n";
}

void deleteStudentByRollNumber()
{
   int roll_no;
   cout << "\nEnter the Roll Number that you want to delete : ";
   cin >> roll_no;

   bool found = false;
   for (int i = 0; i < number_of_students; i++)
   {
      if (roll_no == students[i].roll_number)
      {
         found = true;
         for (int j = i; j < 109; j++)
            students[j] = students[j + 1];
         number_of_students--;
      }
   }

   if (found)
   {
      cout << "\nThe Roll Number is removed Successfully\n";
   }
   else
   {
      cout << "\nRoll number not found in the database\n";
   }
}

void updateStudentDetails()
{

   cout << "\nEnter the roll number whose details you want to update : ";
   int roll_no;
   cin >> roll_no;

   bool found = false;
   for (int i = 0; i < number_of_students; i++)
   {
      if (students[i].roll_number == roll_no)
      {

         found = true;
         cout << "\n1. update first name\n"
                 "2. update last name\n"
                 "3. update roll number.\n"
                 "4. update CGPA\n"
                 "5. update courses\n";

         int choice;
         cin >> choice;

         switch (choice)
         {
         case 1:
            cout << "\nEnter the new first name : ";
            cin >> students[i].first_name;
            break;

         case 2:
            cout << "\nEnter the new last name : ";
            cin >> students[i].last_name;
            break;

         case 3:
            cout << "\nEnter the new roll number : ";
            cin >> students[i].roll_number;
            break;

         case 4:
            cout << "\nEnter the new CGPA : ";
            cin >> students[i].cgpa;
            break;

         case 5:
            cout << "\nEnter the new courses ID: ";
            cin >> students[i].course_id[0] >>
                students[i].course_id[1];
            break;
         }
      }
   }

   if (found)
   {
      cout << "\nDetails updated successfully.\n";
   }
   else
   {
      cout << "\nStudent not found in the database.\n";
   }
}

int main()
{
   int choice;
   while (true)
   {
      cout << "Choices of the tasks that you want to perform\n\n";

      cout << "1.Add new Student to the database\n";

      cout << "2. Search Student by Roll Number\n";

      cout << "3. Search Student by First Name\n";

      cout << "4. Search Student by Course Id\n";

      cout << "5. Count Total number of Students\n";

      cout << "6. Delete the Student by Roll Number\n";

      cout << "7. Update Student Details by Roll Number\n";

      cout << "8. Get All Students List\n";

      cout << "9. Exit the program\n";

      cout << "Enter your choice : ";
      cin >> choice;

      switch (choice)
      {
      case 1:
         addStudentDetails();
         break;

      case 2:
         findStudentByRollNumber();
         break;

      case 3:
         findStudentByFirstName();
         break;

      case 4:
         findStudentByCourseId();
         break;

      case 5:
         findTotalStudents();
         break;

      case 6:
         deleteStudentByRollNumber();
         break;

      case 7:
         updateStudentDetails();
         break;

      case 8:
         exit(0);
         break;
      }
   }

   return 0;
}
