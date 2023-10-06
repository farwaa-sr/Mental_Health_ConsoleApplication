#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>
#include <ctime>
#include <iomanip>
#ifdef _WIN32
#include <Windows.h>    
#else
#include <unistd.h>                         
#endif
using namespace std; 
/* GLOBALS: */
//changeColours
const int DEFAULTCOLOUR = 7;
const int GREEN = 10;
const int BLUE = 11;
const int RED = 12;
const int PURPLE = 13;
const int YELLOW = 14;
const int WHITE = 15;
const int blackOnWhite = 240;
void clearScreen(int characterLength) {//to delete previous data from the program
    for (int i = 0; i < characterLength; i++) {
        cout << "\b";
    }
}
void changeColour(int colour) {//function to change color of program text
    HANDLE hConsole;
    
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//an be used by applications that need to read from or write to the console
    SetConsoleTextAttribute(hConsole, colour);
}
void showLoadingScreen() {//function to give a loading screen affect to the user
    int i;
    string closed = "- - -", open = "* * *";
    int colour[] = {RED, GREEN, BLUE};
    
    cout << closed;
    
    for (i = 0; i < 5; i++) {
        Sleep(700);
        
        clearScreen(5);
        changeColour(colour[i]);
        
        cout << open;
        
        Sleep(700);
        
        clearScreen(5);
        changeColour(WHITE);
        
        cout << closed;
    }
    
    clearScreen(5);
    changeColour(WHITE);
}
void TypeWriter(string msg1,unsigned int millis_per_char )//to add a typewriter affect
{   
    for (int x = 0; msg1[x] != 0; x++) 
    {
        if (GetKeyState(VK_SPACE) & 0x8000) //Check if high-order bit is set (1 << 15)/)
        {
            millis_per_char = 1;
        }
        cout << msg1[x];
        Sleep(millis_per_char);
    }
}
void breathing(){
    int i;
    string closed = R"(
   ____  
  / __ \ 
 | |  | |
 | |  | |
 | |__| |
  \____/    
 )", open = R"(     
   ___  
  / _ \ 
 | (_) |
  \___/     
)";
    int colour[] = {RED, GREEN, BLUE};
    
    cout << closed;
    
    for (i = 0; i < 5; i++) {
        Sleep(700);
        clearScreen(50);
        changeColour(colour[i]);
        cout << open;
        Sleep(800);
        clearScreen(50);
        changeColour(WHITE);
        cout << closed;
    }
    
    clearScreen(50);
    changeColour(WHITE);
    system("cls");
}
void breaking(){//breaking between sections to structure the program
    cout<<"_______________________________________________________________________________";
}
void quicken(){//prints the 'you can increase speed'
    cout<<"\n(Press the space bar to increase the speed of typing animation.)\n";
}
void gotoXY(int x, int y)   // used to change cursor position in the output console/terminal:
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void LineBreak(char lineType, int lineLength)   // line breaks.
{
    
    for (int i = 0; i <= lineLength; i++)
    {
        cout << lineType;
    }

}
void Main();    // forward declaration of main menu
//EMERGENCY FRIEND FUNCTION STARTS:
void emergency(int patient,int threat,string mental_health){//this is an emergency friend function to be called in any sub class/classes to monitor the patients health in case of emergencies
    showLoadingScreen();//calls loading screen function.
    breaking();
    system("cls");
    quicken();
    long int contact;//long integer type variable to store contact number.
    const int ambulance=115;//integer constant stores ambulance number
    string response;//stores user response inputs
    changeColour(YELLOW);
    if (mental_health=="ADHD"||mental_health=="Insomnia"){//if the patients mental illness is ADHD then ask the set of questions to determine whether the user is in a state of distress.
        TypeWriter("\nAre your muscles tense or heart racing? (enter yes or no)\n",60);
        cin>>response;
        if (response=="yes"||response=="Yes"||response=="YES")//if yes then advise user to calm nerves with this exercise
        {
            threat=threat+1;
            TypeWriter("\nDo the following: \n\tClose your eyes, and deep breathe for 20 seconds.\n\tStand up and stretch for at least 5 minutes.\n\tTake a walk out of your current environment\n",60);
            TypeWriter("\nDeep breathing can help as it releases anxiety and relax your body from head to toe.\n",60);
            cout<<"\nDo you feel better now? (yes or no)\n";
            cin>>response;
            if (response=="no"||response=="No"||response=="NO")
            {
                threat=threat+1;
                if (threat>10)//if threat to patients life is very high, automatically call ambulance.
                {
                    cout<<setw(30)<<"\n--------Calling Ambulance--------\n";
                    TypeWriter("\n\tAn ambulance is on its way. Meanwhile, please continue deep breathing.\n",60);
                    cout<<"\n---------Calling "<<ambulance<<"--------- at "<<__TIME__;
                    abort;//ends program when user is no longer active on the program.
                }
                else TypeWriter("\nYou're uneasiness can be resolved with a few more exercises!\n",60);
            }
            else
            {
                threat=threat-1;//threat level decreases (so decrement)
                cout<<"\nStay safe.\n";//ending message of friend function.
            }
        }
        else
        {
            threat=threat-1;//threat level decreases (so decrement)
            cout<<"\nStay safe.\n";//ending message of friend function.
        }
    }
    else if(mental_health=="Depression"||mental_health=="Anxiety"||mental_health=="OCD"){//if patient has depression
        TypeWriter("\nAre you having any suicidal thoughts and/or thoughts of self-harm? (enter yes or no)\n",60);
        cin>>response;
        if (response=="yes"||response=="Yes"||response=="YES")
        {
            threat=threat+1;
            TypeWriter("\nDeep breathe:\n\tSlowing your breath can help you realise the anxiety and relax your body from head to toe. Deep breathe for at least 5 minutes scattered throughout your day.\n",60);
            cout<<"\nDo you feel better? (yes or no)\n";
            cin>>response;
            if (response=="no"||response=="No"||response=="NO")//if not, offer to call an emergency contact whom the patient may feel comfortable opening up to
            {
                threat=threat+1;//increase threat level
                breaking();
                cout<<"\n\tEnter an emergency contact number: ";
                cin>>contact;
                cout<<"\n---------Calling "<<contact<<"---------";
                cout<<"\n\tEnter any word to end call.\n";
                cout<<"\nCurrent time: "<< __TIME__<<endl;
                cin>>response;
                cout<<"\nCurrent time: "<<__TIME__;
                cout<<"\nAfter having this conversation with your friend, did it eliminate the dark thoughts you were having? (yes or no)\n";
                cin>>response;
                if ((response=="no"||response=="NO"||response=="No")&&threat>10)
                {
                    threat=threat+1;
                    cout<<setw(30)<<"\n--------Calling Ambulance--------\n";
                    cout<<"\n\tAn ambulance is on its way. Meanwhile, please continue deep breathing.\n";
                    cout<<"\n---------Calling "<<ambulance<<"--------- at "<<__TIME__;
                    abort;
                }
                else {
                    threat=threat-1;//threat leve decreases as the patient calms down
                    cout<<"\nStay safe.\n";//ending message of friend function.
            }
            }
            else {
                threat=threat-1;//threat leve decreases as the patient calms down
                cout<<"\nStay safe.\n";//ending message of friend function.
            }
        }
    }  
    if (threat>=5&&threat<=10)//to monitor the patients health threat level
    {
        TypeWriter("\nYour stress levels are high, but with a little more practice with this self help guidance, you can reduce it to an insignificant level.\n",60);
    }
    else if(threat<5){TypeWriter("Congrats! Your stress levels have decreased significantly",60);}    
}
//Emergency Friend function Ends here.
//BASE CLASS mental_illness BEGINS HERE:
class mental_illness
{
protected://data members protected so we can use it in sub classes
    string name;
    int age;
    int threat=0;
public://member function publicly defined
    string illness;
    int patient_num;
    void set_patient_num(int patient){
        patient_num=patient;
    }
    void set_illness(string illness_name){//member function to set the illness value
        illness=illness_name;
    }
    void set_threat(int temp){//member function to set the threat value
        threat=temp;
    }
    void User_data(int patientNum){//member function to get users data.
        system("cls");//this clears the screen of previous data
        quicken();//this function call tells the user they can increase the speed of the typewriter effect
        changeColour(BLUE);//this changes the color of the text to BLUE
        TypeWriter("Enter Your Name: ",40);
        cin.ignore();
        getline(cin,name);
        TypeWriter("\nEnter your age: ",40);
        cin>>age;
    }
    friend void emergency(int patient, string illness, int threat);
    //virtual functions to be overrided in sub classes.
    virtual void menu(){}
    virtual void exercises(){}
    virtual void self_help_advice(){}
    virtual void contact_therapists(){}
    virtual void SelectType(){}//overrided in anxiety and insomnia
    virtual void SetTime(){}//overrided in sleep cycle inheriting insomnia
    virtual void DisplayTime(){}//overrided in sleep cycle inheriting insomnia
    virtual void addTime(){}//overided in sleep cycle inheriting insomnia
    virtual void SelectCycle(){}//overrided in sleep cycle inheriting insomnia
    virtual void info(){}//overrided in insomnia and anxiety
    virtual void Menu(){}//overrided in the subclasses of depression
    virtual void MDD_Menu(){}//overrided in Type1_Depression inheriting Depression
    virtual void psychotherapy(){}//overrided in the subclasses of depression
    virtual void PDD_Menu(){}//overrided in Type2_Depression inheriting Depression
    void vent(){//this member function is created for the patients to vent to a virtual listener.
        breaking();
        system("cls");
        quicken();
        changeColour(YELLOW);
        int mood;//input users mood
        string text;
        TypeWriter("Welcome to the venting session. In this, you can freely have a conversation with us, expressing your thoughts and feelings. This data will remain highly confidential so you can comfortably condfide.\n\n ",60);
        TypeWriter("Hi ",60);
        cout<<name;//give the user a personalized experience to make them feel like theyre are talking to a real person
        TypeWriter(", how was your day from a scale of 1-10? (0-5 being bad and 6-10 being good)",60);
        InvalidEntry://goto statement for invalid entries.
        cin>>mood;//cin the mood of the user and accirding to that the systems behavious will change.
        if (mood>=0&&mood<=5)
        {
            TypeWriter("Why do you feel as though you had a bad day?\n",60);
            getline(cin,text);
            cin.ignore();//used because i am getting a string input from the user into the same variable multiple times. So i need to empty the string before more is processed
                TypeWriter("\n\tI understand. You see, If we're feeling sad when we wake up, or sadness creeps upon us for no apparent reason during the day, this is troubling.\nThat's when it's important to pay attention to that feeling and investigate where it's coming from. Sadness doesn't appear for 'no reason', it's a matter of finding out the origin of that feeling.\nEven if you don't know why you're sad, there are ways you can help yourself in these challenging moments.\nYour mental health can suffer at times, but those moments aren't permanent.\nUnderstanding that feeling sad is a part of life can help you feel better. You know that these emotions are normal and that they pass. But there are reasons for them and it's important to explore the origin of the feelings related to your behavioral health, and prevent yourself from having a difficult time",60);
                TypeWriter("\nSo, what do you think has been bothering you today? (can be multiple reasons)\n",60);
                getline(cin,text);
                cin.ignore();
                TypeWriter("\nAnd why do you think you're bothered by these things?\n",60);
                getline(cin,text);
                cin.ignore();
                TypeWriter("\n That's understandable. Now that you've written down and vented, do you feel better?\n",60);
                cin>>text;
                if (text=="yes"||text=="Yes"||text=="YES")
                {
                    TypeWriter("\n Im glad! I hope you have a great day moving forward.\n",60);
                    breaking();
                    system("cls");
                    menu();//go back to menu
                }
                else{
                    TypeWriter("I see. May i recommend you to some therapists?\n",60);//if the system cannot think of anymore advice and the user feels no different than they first entered the program, then go to advice member function
                    cin.ignore();
                    getline(cin,text);
                    if (text=="yes"||text=="Yes"||text=="YES")
                    {
                        contact_therapists();
                    }
                    else
                    {
                        emergency(patient_num,threat,illness);//emergency in case the patient may be under threat
                    }
                }
        }
        else if(mood>5&&mood<=10)
        {
            TypeWriter("Amazing! What put you in such a good mood?\n",60);
            getline(cin,text);//let the user explain why exactly they feel good.
            cin.ignore();
            TypeWriter("\nWell, Im glad you're having a great day.\n",60);
            menu();
        }
        else {cout<<"\nINVALID ENTRY PLEASE TRY AGAIN.\n"; goto InvalidEntry;}//exception handler        
    }
};
//BASE CLASS mental_illness ENDS HERE.
//Sub class: Depression
class Depression:public mental_illness{
    int choice;//to store users choice
    public:
    friend void emergency(int patient, int threat, string mental_health);
    void menu(){//this is the main menu for depression.
        //breathing();
        breaking();
        system("cls");
        showLoadingScreen();
        quicken();
        changeColour(BLUE);
        //cout ascii art text
        cout <<R"(
    ____                                 _           
   / __ \___  ____  ________  __________(_)___  ____ 
  / / / / _ \/ __ \/ ___/ _ \/ ___/ ___/ / __ \/ __ \
 / /_/ /  __/ /_/ / /  /  __(__  |__  ) / /_/ / / / /
/_____/\___/ .___/_/   \___/____/____/_/\____/_/ /_/ 
          /_/                                        
)";
        TypeWriter("Welcome to the Depression Self-help Section. Please choose one of the following to get started.\n\t1. Medications\n\t2. Vent\n\t3. Exercises\n\t4. Contact Therapists\n\t5. Exit\n",60);
        Invalid_Entry:
        cin>>choice;
        switch (choice)
        {
        case 1:
        system("cls");
            medications();
            break;
        case 2:
        system("cls");
            vent(); 
            break;
        case 3:
        system("cls");
            exercises();
            break;
        case 4:
        system("cls");
            contact_therapists();
            break;
        case 5:
        system("cls");
            TypeWriter("Thank you for your time. Stay safe.",60);
            break;
        default:
        changeColour(RED);
        cout<<"INVALID ENTRY. PLEASE TRY AGAIN: ";
        changeColour(BLUE);
        goto Invalid_Entry;
            break;
        }
    }
    void exercises(){//member function to display kinds of exercises patient can perform to ease their illness
        system("cls");
        quicken();
        changeColour(PURPLE);
        string response;
        float time;//stores duration
        cout<<R"(
    ______                         _                  
   / ____/_  __ ___   _____ _____ (_)_____ ___   _____
  / __/  | |/_// _ \ / ___// ___// // ___// _ \ / ___/
 / /___ _>  < /  __// /   / /__ / /(__  )/  __/(__  ) 
/_____//_/|_| \___//_/    \___//_//____/ \___//____/  
                                                      
)";
        TypeWriter("Some exercises you can put in your daily schedule to improve your lifestyle. Enter a number for the following to know more:\n\t1. Workout\n\t2. Healthy Diet\n\t3. Meditation\n\t4. Exit",60);
        InvalidEntry:
        cin>>choice;
        switch (choice)
        {
        case 1://workouts case, calculates time spent in working out and displays message accordingly
        system("cls");
            TypeWriter("\nAerobic workouts are most associated with positive results in treating depression. Enter the unit of time you wish to use (hrs/min/sec): \n",60);
            cin>>response;
            TypeWriter("\nEnter duration of working out/goin on a walk per day: ",60);
            cin>>time;
            if (response=="hrs")
            {
                time=time*60;//converting hours to minutes
            }
            else if (response=="sec")
            {
                time=time/60;//converting seconds to minutes
            }
            if (time>=25&&time<=35)//if the right time spent
            {
                TypeWriter("\nAmazing! Getting around 30 minutes per day means about 150 minutes per week on average. And this is recommended by most therapists. To gain moderate-intensity aerobic activity is the ideal.\nTry to schedule 2 sessions for muscle strengthening per week too. This can be Weightlifting, yoga, Pilates or similar exercises\n",60);
            }
            else if (time>5&&time<25)//if lower time spent
            {
                TypeWriter("\nThis is lower than average, but still significant. Try increasing this to about 30 minutes per day!\n",60);
            }
            else if (time>35&&time<90)//if more time spent
            {
                TypeWriter("\nIt seems that you are getting more than enough exercise. Keep up the good work!\n",60);
            }
            else if(time>=90)//if too much time spent
            {
                TypeWriter("That's a lot of exercise, try not to overwork yourself!\n",60);
            }
            else TypeWriter("That's hardly anything!! Try to increase your exercise time slowly to 10 minutes, then to 15, and finally 20.\n ",60);//if insignificant time spent
            system("pause");//stops program for a moment and continues when user enters a key
            exercises();//goes back to exercises function menu
            break;
        case 2://eating healthy case
            TypeWriter("\nEating a Healthy Diet improves your mood and concentration, as well as provide energy for your workouts. Eat lots of vegetables, fruits, whole grains, low-fat dairy products, and lean protiens. Avoid foods that are high in refined sugar, saturated fats, or salt.\n",60);
            system("pause");
            exercises();
        break;
        case 3://meditation case
            meditation:
            TypeWriter("\nChoose a kind of meditation to continue:\n\t1. mindfulness\n\t2. spiritual\n\t3. focused\n\t4. movement\n\t5. Exit",60);
            cin>>choice;
            switch (choice)//types of meditation explainations
            {
            case 1:
                TypeWriter("\nMindfulness Meditation\n\tPay attention to your thoughts as they pass your mind. You don’t judge the thoughts or become involved with them. You simply observe and take note of any patterns.\nThis practice combines concentration with awareness. You may find it helpful to focus on an object or your breath while you observe any bodily sensations, thoughts, or feelings.\nThis type of meditation is good for people who don’t have a teacher to guide them, as it can be easily practiced alone.\n",60);
                system("pause");
                goto meditation;
                break;
            case 2:
                TypeWriter("\nSpiritual meditation\n\tSpiritual meditation is used in Eastern religions, such as Hinduism and Daoism, and in Christian faith.\nIt’s similar to prayer in that you reflect on the silence around you and seek a deeper connection with your God or Universe.\nEssential oils are commonly used to heighten the spiritual experience. Popular options include:\n\t- frankincense\n\t- myrrh\n\t- sage\n\t- cedar\n\t- sandalwood\n\t- palo santo\n Spiritual meditation can be practiced at home or in a place of worship. This practice is beneficial for those who thrive in silence and seek spiritual growth.\n",60);
                system("pause");
                goto meditation;
                break;
            case 3:
                TypeWriter("\n Focused meditation\n\tFocused meditation involves concentration using any of the five senses.\nFor example, you can focus on something internal, like your breath, or you can bring in external influences to help focus your attention.\nTry counting mala beads, listening to a gong, or staring at a candle flame.\nThis practice may be simple in theory, but it can be difficult for beginners to hold their focus for longer than a few minutes at first.\nIf your mind does wander, it’s important to come back to the practice and refocus.\nAs the name suggests, this practice is ideal for anyone who requires additional focus in their life.\n",60);
                system("pause");
                goto meditation;
                break;
            case 4:
                TypeWriter("Movement meditation\n\tAlthough most people think of yoga when they hear movement meditation, this practice may include walking through the woods, gardening, qigong, and other gentle forms of motion.\nIt’s an active form of meditation where the movement guides you.\nMovement meditation is good for people who find peace in action and prefer to let their minds wander.\n",60);
                system("pause");
                goto meditation;
                break;
            case 5:
            system("cls");
            exercises();
                break;
            default:
            cout<<"INVALID ENTRY. PLEASE TRY AGAIN: ";
            goto InvalidEntry;
                break;
            }
        break;
        case 4://exit
        system("cls");
        menu();//go back to menu
        break;
        default:
        cout<<"INVALID ENTRY. PLEASE TRY AGAIN: ";
        goto InvalidEntry;
            break;
        }
    }
    void contact_therapists(){//this member function provides a list of therapists in Islamabad according to the patients preference in case they wish to seek professional help
        system("cls");
        changeColour(WHITE);
        quicken();
        char preference;
        string ans;
        cout<<R"(
   ______            __             __     ____      ____     
  / ____/___  ____  / /_____ ______/ /_   /  _/___  / __/___  
 / /   / __ \/ __ \/ __/ __ `/ ___/ __/   / // __ \/ /_/ __ \ 
/ /___/ /_/ / / / / /_/ /_/ / /__/ /_   _/ // / / / __/ /_/ / 
\____/\____/_/ /_/\__/\__,_/\___/\__/  /___/_/ /_/_/  \____(_)
                                                              
)"<<endl;
        cout<<"\nHi "<<name<<", we're glad you are contacting professional help. Based on your preferences, we will provide a list of therapists in Islamabad you can contact for depression.\n\t Would you like a male therapist, female therapist, or do you have no preference? (enter M, F or N)\n";
        InvalidEntry:
        cin>>preference;//take gender preference as input.
        if (preference=='M')
        {
            if (age>=10)//if they are adolescents/adults/elderly
            {
                    changeColour(BLUE);
                    TypeWriter("\n1. Muhammad Sumair (licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Psychology\n\t- Psycotherapy\nSCOPE:\n\t- Depression\n\t- Anxiety Disorders\n\t- Forensic\n\t- Violence\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Direct payment\n\nCONTACT:\n\t- ext: 03473401230\n\n",60);
                    TypeWriter("Go back to main menu?\n",60);
                    cin>>ans;
                    if (ans=="YES"||ans=="Yes"||ans=="yes")
                    {
                        menu();
                    }
                    else abort;
            }
            else if (age<10)//if they are children.
            {
                TypeWriter("\n1. Muhammad Sumair (licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Psychology\n\t- Psycotherapy\nSCOPE:\n\t- Depression\n\t- Anxiety Disorders\n\t- Forensic\n\t- Violence\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Direct payment\n\nCONTACT:\n\t- ext: 03473401230\n\n",60);
                    TypeWriter("Go back to main menu?\n",60);
                    cin>>ans;
                    if (ans=="YES"||ans=="Yes"||ans=="yes")
                    {
                        menu();
                    }
                    else abort;
            }          
        }
        else if(preference=='F'){
            if (age>=10)//if they are adolescents/adults/elderly
            {
                    changeColour(BLUE);
                    TypeWriter("\n1. Heena Chaudhary (psychologist-clinical).\nSERVICES:\n\t- Coaching\n\t- General/Career/Marriage Counselling\n\t- Individual and Couples therapy\n\t- Psychology (Clinical)\nSCOPE:\n\t- Adjusting to Change/Life Transitions\n\t- Attatchment Issues\n\t- Divorce and/or Seperation\n\t- Emotional Abuse\n\t- Online Counseling\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Please Inquire\n\nCONTACT:\n\t- ext: 03325319244\n\t- Whatsapp: +923156678807\n\n",60);
                    changeColour(YELLOW);
                    TypeWriter("2. Miss Zarqa Aijaz (MSC,PMDC, Psychologist)\nSERVICES:\n\t- Assessment\n\t- Counselling\nSCOPE:\n\t- - Adjusting to Change/Life Transitions\n\t- Anger Management Issues\n\t- Anxiety Disorders\n\t- Behavioral and Emotional Problems\n\t- Depression\n\t- Relationship Counselling\nFLUENCY:\n\t- FLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Please inquire.\nCONTACT: 03170355515\n",60);
                    TypeWriter("Go back to main menu?\n",60);
                    cin>>ans;
                    if (ans=="YES"||ans=="Yes"||ans=="yes")
                    {
                        menu();
                    }
                    else abort;
            }
            else if (age<10)//if they are children.
            {
                TypeWriter("Unfortunately there are no female psychologists who deal with depression in children in islamambad. However, there is 1 male psychologist: ",60);
                TypeWriter("\n1. Muhammad Sumair (licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Psychology\n\t- Psycotherapy\nSCOPE:\n\t- Depression\n\t- Anxiety Disorders\n\t- Forensic\n\t- Violence\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Direct payment\n\nCONTACT:\n\t- ext: 03473401230\n\n",60);
                    TypeWriter("Go back to main menu?\n",60);
                    cin>>ans;
                    if (ans=="YES"||ans=="Yes"||ans=="yes")
                    {
                        menu();
                    }
                    else abort;
            }
        }
        else if (preference=='N')
        {
            if (age>=10)//if they are adolescents/adults/elderly
            {
                    changeColour(BLUE);
                    TypeWriter("\n1. Heena Chaudhary (psychologist-clinical).\nSERVICES:\n\t- Coaching\n\t- General/Career/Marriage Counselling\n\t- Individual and Couples therapy\n\t- Psychology (Clinical)\nSCOPE:\n\t- Adjusting to Change/Life Transitions\n\t- Attatchment Issues\n\t- Divorce and/or Seperation\n\t- Emotional Abuse\n\t- Online Counseling\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Please Inquire\n\nCONTACT:\n\t- ext: 03325319244\n\t- Whatsapp: +923156678807\n\n",60);
                    changeColour(YELLOW);
                    TypeWriter("2. Miss Zarqa Aijaz (MSC,PMDC, Psychologist)\nSERVICES:\n\t- Assessment\n\t- Counselling\nSCOPE:\n\t- - Adjusting to Change/Life Transitions\n\t- Anger Management Issues\n\t- Anxiety Disorders\n\t- Behavioral and Emotional Problems\n\t- Depression\n\t- Relationship Counselling\nFLUENCY:\n\t- FLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Please inquire.\nCONTACT: 03170355515\n",60);
                    TypeWriter("\n3. Muhammad Sumair (licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Psychology\n\t- Psycotherapy\nSCOPE:\n\t- Depression\n\t- Anxiety Disorders\n\t- Forensic\n\t- Violence\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Direct payment\n\nCONTACT:\n\t- ext: 03473401230\n\n",60);
                    TypeWriter("Go back to main menu?\n",60);
                    cin>>ans;
                    if (ans=="YES"||ans=="Yes"||ans=="yes")
                    {
                        menu();
                    }
                    else abort;
            }
            else if (age<10)//if they are children.
            {
                TypeWriter("\n1. Muhammad Sumair (licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Psychology\n\t- Psycotherapy\nSCOPE:\n\t- Depression\n\t- Anxiety Disorders\n\t- Forensic\n\t- Violence\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Direct payment\n\nCONTACT:\n\t- ext: 03473401230\n\n",60);
                    TypeWriter("Go back to main menu?\n",60);
                    cin>>ans;
                    if (ans=="YES"||ans=="Yes"||ans=="yes")
                    {
                        menu();
                    }
                    else abort;
            }
        }
        else
        {
            cout<<"INVALID ENTRY> PLEASE TRY AGAIN: ";
            goto InvalidEntry;
        }
    }
     void medications(){//to provide information on medications commonly use to treate the illness
        system("cls");
        changeColour(RED);
        cout<<R"(
    __  ___         ___            __  _                 
   /  |/  /__  ____/ (_)________ _/ /_(_)___  ____  _____
  / /|_/ / _ \/ __  / / ___/ __ `/ __/ / __ \/ __ \/ ___/
 / /  / /  __/ /_/ / / /__/ /_/ / /_/ / /_/ / / / (__  ) 
/_/  /_/\___/\__,_/_/\___/\__,_/\__/_/\____/_/ /_/____/  
                                                         
)"<<endl;
        TypeWriter("\n(DO NOT TAKE THESE MEDICATIONS WITHOUT SEEKING PROFESSIONAL HELP FIRST.)\n",60);
        changeColour(PURPLE);
        TypeWriter("\nYour healthcare provider may prescribe:\n\t1.Antidepressants\n\t2. antipsychotic medications\nEnter a number to get more intel on the specified medications and enter any other digit to exit: ",60);
        cin>>choice;
        if (choice==1)
        {
            TypeWriter("\nTetracyclic antidepressant\nMaprotiline is used to treat depression and anxiety. It also works by balancing neurotransmitters to ease symptoms of depression.\nCommon side effects of this drug include:\n\tDrowsiness\n\tWeakness\n\tLightheadedness\n\tHeadache\n\tBlurry vision\n\tDry mouth\n",60);
        }
        else if (choice==2)
        {
            TypeWriter("\nPossible side-effects of atypical antipsychotics include:\n\tDry mouth\n\tDizziness\n\tBlurred vision\n\tSeizures (rarely)\n",60);
        }
        else
        {
            system("cls");
            emergency(patient_num,threat,"Depression");
        }
        system("pause");
        system("cls");
        menu();
    }
};
//source subclasses
class Type1_depression:public Depression{//this is a subclass for a type of depression
    int choice;
    public:
    void Menu(){
        menu();
        MDD_Menu();
        system("pause");
        system("cls");
    }
    void MDD_Menu(){
        system("cls");
        changeColour(BLUE);
        cout<<R"(
  __  __ _____  _____  
 |  \/  |  __ \|  __ \ 
 | \  / | |  | | |  | |
 | |\/| | |  | | |  | |
 | |  | | |__| | |__| |
 |_|  |_|_____/|_____/ 
                       
                       
)"<<endl;
        TypeWriter("\nAs you have Major Depressive Disorder and this is a type of depression; some extra facillities can be provided to you to tackle this kind of Depression. Please choose one to continue:\n\t1. Advice\n\t2. Psychotherapy\n\t3. Exit\n",60);
        InvalidChoice:
        cin>>choice;
        switch (choice)
        {
        case 1:
            system("cls");
            self_help_advice();
            break;
        case 2:
            system("cls");
            psychotherapy();
            break;
        case 3:
            cout<<"Thank You for you time. Bye.";
            break;
        default:
            cout<<"Invalid Entry. Please try again: ";
            goto InvalidChoice;
            break;
        }
    }
    void self_help_advice(){
        system("cls");
        changeColour(YELLOW);
        cout<<R"(
              _       _          
     /\      | |     (_)         
    /  \   __| |_   ___  ___ ___ 
   / /\ \ / _` \ \ / / |/ __/ _ \
  / ____ \ (_| |\ V /| | (_|  __/
 /_/    \_\__,_| \_/ |_|\___\___|
                                 
                                 
)"<<endl;
        TypeWriter("\nHere are some lifestyle changes which can significantly improve your symptoms. Choose one to continue:\n\t1. Food and Drink\n\t2. Sleep Schedule\n\t3. Exit",60);
        InvalidChoice:
        cin>>choice;
        switch (choice)
        {
        case 1:
            system("cls");
            TypeWriter("\nEat foods that contain omega-3 fatty acids; like salmon.\n\tfoods rich in B vitamins; like beans and whole grains\n\tfoods containing magnesium; like nuts, seeds, and yogurt\nAvoid alcohol and processed foods\n",60);
            self_help_advice();
            break;
        case 2:
            system("cls");
            TypeWriter("\nGetting 7-9 hours is vital. Speak to a doctor if you're having trouble sleeping or oversleeping.\n",60);
            self_help_advice();
            break;
        case 3:
            MDD_Menu();
            break;        
        default:
            cout<<"Invalid Entry. Please try again: ";
            goto InvalidChoice;
            break;
        }
    }
    void psychotherapy(){
        system("cls");
        cout<<R"(
  _____                _           _   _                                
 |  __ \              | |         | | | |                               
 | |__) |__ _   _  ___| |__   ___ | |_| |__   ___ _ __ __ _ _ __  _   _ 
 |  ___/ __| | | |/ __| '_ \ / _ \| __| '_ \ / _ \ '__/ _` | '_ \| | | |
 | |   \__ \ |_| | (__| | | | (_) | |_| | | |  __/ | | (_| | |_) | |_| |
 |_|   |___/\__, |\___|_| |_|\___/ \__|_| |_|\___|_|  \__,_| .__/ \__, |
             __/ |                                         | |     __/ |
            |___/                                          |_|    |___/ 
)"<<endl;
        TypeWriter("\nPsychotherapy\n\tAKA Talk therapy. Speaking to a therapist on a regular basis to talk about your condition.\nBENEFITS:\n\t- Adjust to a crisis or other stressfull event\n\t- Replace negative beliefs and behaviours with positive ones.\n\t- Improve your communication skills\n\t- Increase your self-esteem\n\t- Regain a sense of satisfaction and control in your life\n",60);
        system("pause");
        MDD_Menu();
    }
};
class Type2_depression:public Depression{//this is a subclass for another type of depression
    int choice;
    public:
    void Menu(){
        menu();
        PDD_Menu();
        system("pause");
        system("cls");
    }
    void PDD_Menu(){
        system("cls");
        changeColour(YELLOW);
        cout<<R"(
    ____  ____  ____ 
   / __ \/ __ \/ __ \
  / /_/ / / / / / / /
 / ____/ /_/ / /_/ / 
/_/   /_____/_____/  
                     
)"<<endl;
        TypeWriter("\nAs you have Persistent Depressive Disorder (AKA Dysthymia) and this is a type of depression; some extra facillities can be provided to you to tackle this kind of Depression. Please choose one to continue:\n\t1. Advice\n\t2. Therapy\n\t3. Exit\n",60);
        InvalidChoice:
        cin>>choice;
        switch (choice)
        {
        case 1:
            system("cls");
            self_help_advice();
            break;
        case 2:
            system("cls");
            psychotherapy();
            break;
        case 3:
            cout<<"Thank You for you time. Bye.";
            break;
        default:
            cout<<"Invalid Entry. Please try again: ";
            goto InvalidChoice;
            break;
        }
    }
    void self_help_advice(){
        system("cls");
        changeColour(YELLOW);
        cout<<R"(
              _       _          
     /\      | |     (_)         
    /  \   __| |_   ___  ___ ___ 
   / /\ \ / _` \ \ / / |/ __/ _ \
  / ____ \ (_| |\ V /| | (_|  __/
 /_/    \_\__,_| \_/ |_|\___\___|
                                 
                                 
)"<<endl;
        TypeWriter("\nHere are some lifestyle changes which can significantly improve your symptoms.",60);
        TypeWriter("\n\t- Exercise at least 3 times a week\n\t- Eating a diet which consists of natural foods\n\t- Take supplements like fish oil\n\t- Write a journal\n",60);
        system("pause");
        PDD_Menu();
    }
    void psychotherapy(){
        system("cls");
        cout<<R"(
  _____                _           _   _                                
 |  __ \              | |         | | | |                               
 | |__) |__ _   _  ___| |__   ___ | |_| |__   ___ _ __ __ _ _ __  _   _ 
 |  ___/ __| | | |/ __| '_ \ / _ \| __| '_ \ / _ \ '__/ _` | '_ \| | | |
 | |   \__ \ |_| | (__| | | | (_) | |_| | | |  __/ | | (_| | |_) | |_| |
 |_|   |___/\__, |\___|_| |_|\___/ \__|_| |_|\___|_|  \__,_| .__/ \__, |
             __/ |                                         | |     __/ |
            |___/                                          |_|    |___/ 
)"<<endl;
        TypeWriter("\nPsychotherapy\n\tAKA Talk therapy. Speaking to a therapist on a regular basis to talk about your condition.\nBENEFITS:\n\t- Adjust to a crisis or other stressfull event\n\t- Replace negative beliefs and behaviours with positive ones.\n\t- Improve your communication skills\n\t- Regain a sense of satisfaction and control in your life\n\t- Set realistic goals for yourself\n\t- Identify thoughts, behaviors, and emotions\n",60);
        system("pause");
        PDD_Menu();
    }
};
//source subclasses end
//Subclass END: Depression

//Subclass: insomnia
class Insomnia : public mental_illness
{
    private:
        char select;
        
    public:
        
        void menu();    // subclass menu
        void virtual info()    // general info about insomnia
        {
            TypeWriter("\nInsomnia is a type of sleep disorder. Individuals with insomnia find it difficult to fall asleep, stay asleep, or both. \n\nPeople with insomnia often don't feel refreshed when they wake up from sleeping, either. This can lead to fatigue and \nother symptoms.\n", 35);
            changeColour(YELLOW);      
            LineBreak('=', 95);
            changeColour(PURPLE);        
            TypeWriter(R"(                    
 __             __  ___  __         __  
/__` \ /  |\/| |__)  |  /  \  |\/| /__` 
.__/  |   |  | |     |  \__/  |  | .__/ 
----------------------------------------)""\n", 1);

            changeColour(DEFAULTCOLOUR);
            TypeWriter("\nFollowing are the common symptoms of insomnia:\n \n\tTrouble falling asleep \n\tFailure to sleep through the night \n\tWaking up earlier than usual \n\tDaytime sleepiness \n\tReduced ability to concentrate \n\tIrritability\n\n", 35);



            changeColour(YELLOW);      
            LineBreak('=', 95);
        }
       
        void exercises()  // overridden exercises function.
        {
            char selc;
            string back;

            showLoadingScreen();
            system("cls");
            changeColour(GREEN);
            TypeWriter(R"(
                ___  ____ ____ ____ ___ _  _ _ _  _ ____    ____ _  _ ____ ____ ____ _ ____ ____ ____ 
                |__] |__/ |___ |__|  |  |__| | |\ | | __    |___  \/  |___ |__/ |    | [__  |___ [__  
                |__] |  \ |___ |  |  |  |  | | | \| |__]    |___ _/\_ |___ |  \ |___ | ___] |___ ___] )""\n", 3);

            changeColour(YELLOW);
            LineBreak('=', 119);

            changeColour(BLUE);
            gotoXY(24, 9);  cout << "[1] 4-7-8 breathing technique";             
            gotoXY(24, 10); cout << "[2] Three-part breathing";        
            gotoXY(24, 11); cout << "[3] Box breathing";
            gotoXY(24, 12); cout << "[4] Go Back";

            changeColour(DEFAULTCOLOUR);
            cout << "\nEnter the number to select from the above exercises: ";
            cin >> selc;
            switch (selc)
            {
                case '1':
                {   
                    changeColour(WHITE);
                    cout << "\n Here’s how to practice the 4-7-8 breathing technique:\n\n";
                    changeColour(PURPLE);
                    TypeWriter("1. Allow your lips to gently part.\n2. Exhale completely, making a breathy whoosh sound as you do.\n3. Press your lips together as you silently inhale through the nose for a count of 4 seconds.\n4. Hold your breath for a count of 7.\n5. Exhale again for a full 8 seconds, making a whooshing sound throughout.\n6. Repeat 4 times when you first start. Eventually work up to 8 repetitions.""\n" , 30);

                    invalid:
                    cout << "\n\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        system("cls");
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid;
                    }
                    
                    break;
                }
                case '2':
                {
                    changeColour(WHITE);
                    cout << "\nTo practice the three-part breathing exercise, follow these three steps:\n\n";
                    changeColour(PURPLE);
                    TypeWriter("\n1. Take a long, deep inhale.\n2. Exhale fully while focusing intently on your body and how it feels.\n3. After doing this a few times, slow down your exhale so that it’s twice as long as your inhale.", 30);

                    invalid1:
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid1;
                    }

                    break;
                }
                case '3':
                {
                    changeColour(WHITE);
                    cout << "\nDuring box breathing, you want to focus intently on the oxygen you’re bringing in and pushing out::\n\n";
                    changeColour(PURPLE);
                    TypeWriter("\n1. Sit with your back straight, breathe in, and then try to push all the air out of your lungs as you exhale.\n2. Inhale slowly through your nose and count to 4 in your head, filling your lungs with more air with each number.\n3. Hold your breath and count to 4 in your head.\n4. Slowly exhale through your mouth, focusing on getting all the oxygen out of your lungs.", 30);

                    changeColour(WHITE);
                    TypeWriter("\tBox breathing is a common technique during meditation, a very popular method of finding mental focus and relaxing. Meditation has a variety of known benefits for your overall health.", 50);

                    invalid2:
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid2;
                    }
                    break;
                }
                case '4':
                {
                    menu();
                    break;
                }
                default:
                { 
                    break;
                }

            }
        }
};
//Types of insomnia:
class TypesInsomnia : public Insomnia
{
    private:

    public:
    friend void emergency(int patient, int threat, string mental_health);
    void SelectType(bool isAcute, bool isChronic, bool isTransient)
    {
        // one function for 3 types, because there is not much to write about them (can also be made three different functions).
        if(isAcute)
        {
            changeColour(RED);
            TypeWriter(R"(
                _______                _____       
                ___    |___________  ____  /______ 
                __  /| |_  ___/_  / / /_  __/_  _ \
                _  ___ |/ /__  / /_/ / / /_  /  __/
                /_/  |_|\___/  \__,_/  \__/  \___/ )""\n" , 5);


                changeColour(YELLOW);
                LineBreak('-', 90);

                changeColour(BLUE);
                TypeWriter("\n\nAcute insomnia is the most common type of insomnia. It is short term and lasts for a few days up to a month. It is also commonly called adjustment insomnia because it is usually caused by a change in environment or stressful events.\nSome common causes of acute insomnia are as follows: \n" , 35);
                changeColour(WHITE);
                TypeWriter("\n -> New environment and unfamiliarity\n -> Excessive noise or light\n -> Extremes of temperature\n -> Uncomfortable bed or mattress\n -> New job or school\n -> Relocation to a new place\n -> Jet lag\n -> Work deadlines or examinations\n -> Death of a relative or close friend\n -> Difficulties in a relationship\n -> Physical discomfort such as pain \n -> Certain medications\n -> Acute illness and allergies\n", 35);
        }
        
        if(isChronic)
        {
            changeColour(GREEN);
            TypeWriter(R"(
                _______________                         _____        
                __  ____/___  /_ ______________ _______ ___(_)_______
                _  /     __  __ \__  ___/_  __ \__  __ \__  / _  ___/
                / /___   _  / / /_  /    / /_/ /_  / / /_  /  / /__  
                \____/   /_/ /_/ /_/     \____/ /_/ /_/ /_/   \___/  )""\n" ,5);


                changeColour(YELLOW);
                LineBreak('-', 90);
                
                changeColour(BLUE);
                TypeWriter("\n\nInsomnia is usually a transient or short-term condition. In some cases, insomnia can become chronic or long term. Insomnia is said to be chronic if the patient experiences difficulties in sleeping at least three days a week for at least a month.\nChronic insomnia may be primary or secondary. Primary chronic insomnia is also called idiopathic insomnia because there is no specific cause. Secondary chronic insomnia is also called comorbid insomnia. Comorbid insomnia is more common than primary insomnia and occurs due to other underlying medical conditions (comorbidities).\nCommon causes of chronic insomnia include the following:\n", 35);
                changeColour(WHITE);
                TypeWriter("\n -> Psychological conditions such as depression, anxiety, schizophrenia \n -> The central nervous system (CNS) or brain stimulants such as nicotine and excessive caffeine \n -> Lifestyle factors such as frequent travel causing jet lag, constantly rotating shift work, irregular naps and sleep timings \n -> Age (Insomnia becomes more common with age)\n", 35);

                emergency(patient_num, threat, "Insomnia");
        }

        if (isTransient)
        {
            changeColour(BLUE);
            TypeWriter(R"(
                ________                                _____               _____ 
                ___  __/______________ ________ ___________(_)_____ _______ __  /_
                __  /   __  ___/_  __ `/__  __ \__  ___/__  / _  _ \__  __ \_  __/
                _  /    _  /    / /_/ / _  / / /_(__  ) _  /  /  __/_  / / // /_  
                /_/     /_/     \__,_/  /_/ /_/ /____/  /_/   \___/ /_/ /_/ \__/ )""\n" , 5);

                changeColour(YELLOW);
                LineBreak('-', 90);
                
                changeColour(BLUE);
                TypeWriter("\n\nInsomnia that usually lasts less than a week and does not recur is transient insomnia. \ncommon causes of transient insomnia are:\n", 35);
                changeColour(WHITE);
                TypeWriter("\n -> Caused by another disorder: stress, or depression. \n -> Changes in the sleep environment. \n -> An illness that causes frequent waking or breathing problems.", 35);

        }
        
    }
};
// optimal sleep calculator 
class SleepCycle : Insomnia
{
    private:
        int avgCycle = 90;      // average sleep cycle is 90 mins
        int hours , minutes;    // user time
        int totalHours, totalMinutes;;
        
        char s, op;
        

        Insomnia i; 
        

    public:
        void info() // info about sleeping cycle
        {
            TypeWriter("The sleep cycle is an oscillation between the slow-wave and REM phases of sleep.\nIt is sometimes called the ultradian sleep cycle, sleep dream cycle, or REM-NREM cycle, to distinguish it from the circadian alternation between sleep and wakefulness.\nIn humans this cycle takes 70 to 110 minutes" , 50);
        }
        void SetTime()  // function to enter time HH:MM
        {
            changeColour(WHITE);
            TypeWriter("\nPlease enter the time you want to go to sleep OR you usually go to sleep at:\n" , 15);
            cout << "Enter Hours: ";
            cin >> hours;
            while(hours < 0 || hours > 23)
            {
                TypeWriter("Please Enter correct time, hours cannot be greater than 23, please try again:-\n", 15);
                cout << "Enter hours: ";
                cin >> hours;
            }
            cout << "Enter minutes: ";
            cin >> minutes;
            while(minutes < 0 || minutes > 60)
            {
                TypeWriter("Please Enter correct time, minutes cannot be greater than 60, please try again:-\n", 15);
                cout << "Enter minutes: ";
                cin >> minutes;
            }
            
  
        }
        void DisplayTime()  // Displays time
        {
            if(totalHours > 23) // if the time goes over 23 (meaning if it goes into days instead of hours we subtract 24 from it)
            {   
                totalHours -= 24;   
            }

            changeColour(GREEN);
            cout << endl << "\t\n" <<  setw(2) << setfill('0') << totalHours << " : " << setw(2) << setfill('0') << totalMinutes << endl;

        }
        void addTime(int multiplier)    // actual calculator
        {
            totalMinutes = minutes + avgCycle * multiplier;
            totalHours = hours + totalMinutes / 60;
            totalMinutes %= 60;
        }
        void SelectCycle()  // sub-menu
        {
            up:
            again:
            showLoadingScreen();
            system("cls");
            changeColour(PURPLE);
            TypeWriter(R"(
            ____ _    ____ ____ ___           ____ _   _ ____ _    ____                         
            [__  |    |___ |___ |__]          |     \_/  |    |    |___
            ___] |___ |___ |___ |             |___   |   |___ |___ |___
                ____ ____ _    ____ _  _ _    ____ ___ ____ ____
                |    |__| |    |    |  | |    |__|  |  |  | |__/
                |___ |  | |___ |___ |__| |___ |  |  |  |__| |  \)""\n", 5);

           
            changeColour(DEFAULTCOLOUR);
            TypeWriter("\n\nSelect the number of cycles you want to sleep, note that one cycle is about 90 minutes\n", 2);
            changeColour(YELLOW);
            LineBreak('=', 90);

            //user enters time
            SetTime();
            
                
            changeColour(YELLOW);
            LineBreak('=', 90);

            changeColour(BLUE);
            gotoXY(24, 16);  cout << "[1] One Cycle   (1.5 hours)";             
            gotoXY(24, 17); cout << "[2] Two Cycles   (03 hours)";        
            gotoXY(24, 18); cout << "[3] Three Cycles (4.5 hours)"; 
            gotoXY(24, 19); cout << "[4] Four Cycles  (6 hours)";  
            gotoXY(24, 20); cout << "[5] Five Cycles  (7.5 hours)";
            gotoXY(24, 21); cout << "[6] What is Sleep Cycle";
            gotoXY(24, 22); cout << "[0] Go Back";

            gotoXY(0, 24);
            changeColour(YELLOW);
            LineBreak('=', 90);

            changeColour(WHITE);
            cout << endl;
            s = _getch();
            switch (s)
            {
                case '0':
                {
                    system("cls");
                    i.menu();
                    break;
                }
                case '1':
                {
                    addTime(1);
                    TypeWriter("You choose one cycle, you should set your alarm at: ", 15);
                    DisplayTime();
                    break;
                }
                case '2':
                {
                    addTime(2);
                    TypeWriter("You choose to sleep two cycles, you should set your alarm at: ", 15);
                    DisplayTime();
                    break;
                }
                case '3':
                {
                    addTime(3);
                    TypeWriter("You choose to sleep three cycles, you should set your alarm at: ", 15);
                    DisplayTime();
                    break;
                }
                case '4':
                {
                    addTime(4);
                    TypeWriter("You choose to sleep four cycles, you should set your alarm at: ", 15);
                    DisplayTime();
                    break;
                }
                case '5':
                {
                    addTime(5);
                    TypeWriter("You choose to sleep five cycles, you should set your alarm at: ", 15);
                    DisplayTime();
                    break;
                }
                case '6':
                {
                    info();
                    cout << "\n\n Do you want to select somthing else:(Y/N): ";
                    cin >> op;
                    if(op == 'Y' || op == 'y')
                    {
                        system("cls");
                        goto up;
                    }    
                    else
                    {
                        break;
                    }
                    
                }
                default:
                {
                    goto again;
                    break;
                }
            }
        }
};

// menu
void Insomnia :: menu()
{
   
    // refrence to classes
    TypesInsomnia Ti;
    SleepCycle mySleep;

    int menuItem = 0, x = 9;
	bool isRunning = true;
	string goBack;
    char option;

    changeColour(PURPLE);
    TypeWriter(R"(
               ____   _  __   ____  ____    __  ___   _  __   ____   ___ 
              /  _/  / |/ /  / __/ / __ \  /  |/  /  / |/ /  /  _/  / _ |
             _/ /   /    /  _\ \  / /_/ / / /|_/ /  /    /  _/ /   / __ |
            /___/  /_/|_/  /___/  \____/ /_/  /_/  /_/|_/  /___/  /_/ |_|)""\n", 5);
    
    gotoXY(0, 8);
    changeColour(YELLOW);
    LineBreak('-', 95);

    gotoXY(22,9);
    changeColour(PURPLE); 
    cout << "->";
	
    
	while(isRunning)
	{
        changeColour(BLUE);
		gotoXY(24, 9);  cout << "[1] General Info";             // what is insomnia etc.
		gotoXY(24, 10); cout << "[2] Types of Insomnia";        
		gotoXY(24, 11); cout << "[3] Sleep Cycle Calculator";         // optimal sleep calculator
		gotoXY(24, 12); cout << "[4] Self Help Section";                    
		gotoXY(24, 13); cout << "Main Menu";                

		system("pause > nul"); // the > nul bit causes it the print no message, without this the cursor blinks
		
		if(GetAsyncKeyState(VK_DOWN) && x != 13) //Down-Arrow key pressed
        {
            gotoXY(22,x); 
            cout << "  ";

            x++;

            gotoXY(22,x); 
            changeColour(PURPLE);
            cout << "->";
            menuItem++;
           
            continue;
            
        }
		if(GetAsyncKeyState(VK_UP) && x != 9) // Up-Arrow key pressed
        {
            gotoXY(22,x); 
    
            cout << "  ";
            x--;
            
            gotoXY(22,x);
            changeColour(PURPLE);
            cout << "->";
            menuItem--;
            continue;
        }
			
		if(GetAsyncKeyState(VK_RETURN))
        { // Enter key pressed
			
			switch(menuItem)
            {
                case 0: // general info
                {
                    system("cls");
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(DEFAULTCOLOUR);  
                    info();

                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> goBack;
                    if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                    {
                        isRunning = false; // kills the loop;
                        system("cls");
                        menu();
                    }
                    else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for using";
                        showLoadingScreen();
                        exit(0);
                    }
                    
                    
                
                    break;
                }
                case 1: // types
                {
                    // bools used for parameters belcow
                    bool A, C , T;  //acute, chronic, transient
                    

                    system("cls");
                    changeColour(PURPLE);
                    TypeWriter(R"(
                         ______ __  __   ___    ____   ____
                        /_  __/ \ \/ /  / _ \  / __/  / __/
                         / /     \  /  / ___/ / _/   _\ \  
                        /_/      /_/  /_/    /___/  /___/)""\n" , 5);
                    
                    changeColour(YELLOW);
                    LineBreak('=',95);
                    
                    changeColour(BLUE);
                    gotoXY(24, 9);  cout << "[1] Acute Insomnia";             
                    gotoXY(24, 10); cout << "[2] Chronic Insomnia";        
                    gotoXY(24, 11); cout << "[3] Transient Insomnia "; 
                    gotoXY(24, 12); cout << "[4] Back"; 

                    cout << "\nEnter the number to select from the above options: ";
                    cin >> option;
                    if(option == '1')
                    {
                        system("cls");
                        A = true;
                        C = false;
                        T = false;

                        Ti.SelectType(A, C, T);


                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }

                        
                    } 
                    else if(option == '2')
                    {
                        system("cls");
                        A = false;
                        C = true;
                        T = false;
                        Ti.SelectType(A, C, T);

                        
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                        
                    }
                    else if (option == '3')
                    {
                        system("cls");
                        A = false;
                        C = false;
                        T = true;
                        Ti.SelectType(A, C, T);

                        changeColour(DEFAULTCOLOUR);
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                        
                        
                    }
                    else if(option == '4')
                    {
                        menu();
                    }
                    else
                    {
                        changeColour(YELLOW);
                        LineBreak('_', 50);
                        showLoadingScreen();
                        changeColour(RED);
                        cout << "\nThank you for your time\n";
                        
                    }
                    
                    break;
                }
                case 2: // sleep cycle
                {
                    system("cls");
                    


                    mySleep.SelectCycle();
                    changeColour(DEFAULTCOLOUR);
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> goBack;
                    if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                    {
                        isRunning = false; // kills the loop;
                        system("cls");
                        menu();
                    }
                    else if (goBack == "No" || goBack == "no" || goBack == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        LineBreak('-', 55);
                        changeColour(RED);
                        showLoadingScreen();
                        exit(0);
                    }
                    break;
                }
                case 3: // self help
                {

                    system("cls");
                    changeColour(DEFAULTCOLOUR);
                    cout << "Welcome to self help section!\n";
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(WHITE);
                    TypeWriter(R"(
                        ____ ____ _    ____    _  _ ____ _    ___  
                        [__  |___ |    |___    |__| |___ |    |__] 
                        ___] |___ |___ |       |  | |___ |___ |)""\n", 10);

                    changeColour(YELLOW);
                    LineBreak('=',95);
                    
                    changeColour(BLUE);
                    cout << "\n\t\t\t\t[1] Breathing Exercises\n";             
                    cout << "\t\t\t\t[2] Vent\n";        
                    cout << "\t\t\t\t[3] Go Back\n"; 
                    
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(DEFAULTCOLOUR);
                    cout << "\nEnter the number to select from the above options, or press anyother key to exit: ";
                    cin >> option;
                    if(option == '1')
                    {
                        system("cls");
                        exercises();

                    }
                    else if (option == '2')
                    {
                        system("cls");
                        gotoXY(0, 0);
                        vent();
                        
                    }
                    else if (option == '3')
                    {
                        system("cls");
                        menu();
                    }
                    
                    break;
                }  
                case 4: // back to main
                {
                    system("cls");
                    Main();
                    // use this case to go back to main main menu.
                    break;
                }

				
			    
				
            }		
		
        }

    }
}
//Subclass END: insomnia

//Subclass: Anxiety
class Anxiety : public mental_illness
{
    private:
        char select;
        
    public:
        
        void menu(); //menu for subclass
        void info() //general info realted to anxiety
        {
            TypeWriter("\nAnxiety is a feeling of unease, such as worry or fear, that can be mild or severe\n. Everyone has feelings of anxiety at some point in their life. For example, you may feel worried and anxious about sitting an exam, or having a medical test or job interview.\n During times like these, feeling anxious can be perfectly normal.\nBut some people find it hard to control their worries. Their feelings of anxiety are more constant and can often affect their daily lives.\n", 35);
            changeColour(YELLOW);      
            LineBreak('=', 95);
            changeColour(PURPLE);        
            TypeWriter(R"(                    
 __             __  ___  __         __  
/__` \ /  |\/| |__)  |  /  \  |\/| /__` 
.__/  |   |  | |     |  \__/  |  | .__/ 
----------------------------------------)""\n", 1);

            changeColour(DEFAULTCOLOUR);
            TypeWriter("\nAnxiety is the main symptom of several conditions, including:\n \n\tPanic disorder \n\tFeeling Agitated\n\tFatigue\n\tDifficulty Concentrating \n\tTrouble Falling or Staying Asleep \n\tIrritability \n\tIrrational Fears \n\tAvoiding Social Situations", 35);



            changeColour(YELLOW);    
            LineBreak('=', 95);
        }
        void exercises() //overridden exercises function
        {
            char selc;
            string back;

            showLoadingScreen();
            system("cls");
            changeColour(GREEN);
            TypeWriter(R"(
                ___  ____ ____ ____ ___ _  _ _ _  _ ____    ____ _  _ ____ ____ ____ _ ____ ____ ____ 
                |__] |__/ |___ |__|  |  |__| | |\ | | __    |___  \/  |___ |__/ |    | [__  |___ [__  
                |__] |  \ |___ |  |  |  |  | | | \| |__]    |___ _/\_ |___ |  \ |___ | ___] |___ ___] )""\n", 3);

            changeColour(YELLOW);
            LineBreak('=', 119);

            changeColour(BLUE);
            gotoXY(24, 9);  cout << "[1] 4-7-8 breathing technique";             
            gotoXY(24, 10); cout << "[2] Three-part breathing";        
            gotoXY(24, 11); cout << "[3] Box breathing";
            gotoXY(24, 12); cout << "[4] Go Back";

            changeColour(DEFAULTCOLOUR);
            cout << "\nEnter the number to select from the above exercises: ";
            cin >> selc;
            switch (selc)
            {
                case '1':
                {   
                    changeColour(WHITE);
                    cout << "\n Here’s how to practice the 4-7-8 breathing technique:\n\n";
                    changeColour(PURPLE);
                    TypeWriter("1. Allow your lips to gently part.\n2. Exhale completely, making a breathy whoosh sound as you do.\n3. Press your lips together as you silently inhale through the nose for a count of 4 seconds.\n4. Hold your breath for a count of 7.\n5. Exhale again for a full 8 seconds, making a whooshing sound throughout.\n6. Repeat 4 times when you first start. Eventually work up to 8 repetitions.""\n" , 30);

                    invalid:
                    cout << "\n\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        system("cls");
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid;
                    }
                    
                    break;
                }
                case '2':
                {
                    changeColour(WHITE);
                    cout << "\nTo practice the three-part breathing exercise, follow these three steps:\n\n";
                    changeColour(PURPLE);
                    TypeWriter("\n1. Take a long, deep inhale.\n2. Exhale fully while focusing intently on your body and how it feels.\n3. After doing this a few times, slow down your exhale so that it’s twice as long as your inhale.", 30);

                    invalid1:
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid1;
                    }

                    break;
                }
                case '3':
                {
                    changeColour(WHITE);
                    cout << "\nDuring box breathing, you want to focus intently on the oxygen you’re bringing in and pushing out::\n\n";
                    changeColour(PURPLE);
                    TypeWriter("\n1. Sit with your back straight, breathe in, and then try to push all the air out of your lungs as you exhale.\n2. Inhale slowly through your nose and count to 4 in your head, filling your lungs with more air with each number.\n3. Hold your breath and count to 4 in your head.\n4. Slowly exhale through your mouth, focusing on getting all the oxygen out of your lungs.", 30);

                    changeColour(WHITE);
                    TypeWriter("\tBox breathing is a common technique during meditation, a very popular method of finding mental focus and relaxing. Meditation has a variety of known benefits for your overall health.", 50);

                    invalid2:
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid2;
                    }
                    break;
                }
                case '4':
                {
                    menu();
                    break;
                }
                default:
                { 
                    break;
                }

            }
        }
};
//types of anxiety
class TypesOfAnxiety : public Anxiety
{
    private:

    public:
    void SelectType(bool isGAD, bool isSocialAnxiety, bool isSpecificPhobias, bool isPanicDisorder)     // TYPES OF INSOMNIA: 
        {
            //here we are using one function for all four types
            if(isGAD)
            {
                changeColour(RED);
                TypeWriter(R"(
                      ____                           _ _             _      _               _      _           ____  _                   _           
                     / ___| ___ _ __   ___ _ __ __ _| (_)_______  __| |    / \   _ __ __  _(_) ___| |_ _   _  |  _ \(_)___  ___  _ __ __| | ___ _ __ 
                    | |  _ / _ \ '_ \ / _ \ '__/ _` | | |_  / _ \/ _` |   / _ \ | '_ \\ \/ / |/ _ \ __| | | | | | | | / __|/ _ \| '__/ _` |/ _ \ '__|
                    | |_| |  __/ | | |  __/ | | (_| | | |/ /  __/ (_| |  / ___ \| | | |>  <| |  __/ |_| |_| | | |_| | \__ \ (_) | | | (_| |  __/ |   
                     \____|\___|_| |_|\___|_|  \__,_|_|_/___\___|\__,_| /_/   \_\_| |_/_/\_\_|\___|\__|\__, | |____/|_|___/\___/|_|  \__,_|\___|_|   
                                                                                                        |___/                                          )""\n" , 5);


                    changeColour(YELLOW);
                    LineBreak('-', 90);

                    changeColour(BLUE);
                    TypeWriter("\n\n A person feels anxious on most days, worrying about lots of different things, for a period of six months or more.\nPeople with GAD, however, feel anxious and worried most of the time, not just in specific stressful situations, and these worries are intense, persistent and interfere with their normal lives.\nTheir worries relate to several aspect of everyday life, including work, health, family and/or financial issues, rather than just one issue.\nEven minor things such as household chores or being late for an appointment can become the focus of anxiety, leading to uncontrollable worries and a feeling that something terrible will happen.\nSome common causes of GAD are as follows: \n" , 35);
                    changeColour(WHITE);
                    TypeWriter("\n -> You may have GAD if the specific signs and symptoms are present for six months or more, and on more days than not. These include physical symptoms as well excessive worrying to the point that everyday activities like working, studying or socialising, become difficult.\nPeople with GAD may have related disorders, most commonly depression, social phobia (characterised by avoidance of social situations) or other anxiety conditions. \nThey may also misuse alcohol or drugs and may experience a range of physical health problems such as headaches or bowel complaints.\n", 35);
            }
            
            if(isSocialAnxiety)
            {
                changeColour(GREEN);
                TypeWriter(R"(
                      ____             _       _      _               _      _         
                     / ___|  ___   ___(_) __ _| |    / \   _ __ __  _(_) ___| |_ _   _ 
                     \___ \ / _ \ / __| |/ _` | |   / _ \ | '_ \\ \/ / |/ _ \ __| | | |
                      ___) | (_) | (__| | (_| | |  / ___ \| | | |>  <| |  __/ |_| |_| |
                     |____/ \___/ \___|_|\__,_|_| /_/   \_\_| |_/_/\_\_|\___|\__|\__, |
                                                                                |___/ 
                                                                )""\n" ,5);


                    changeColour(YELLOW);
                    LineBreak('-', 90);
                    
                    changeColour(BLUE);
                    TypeWriter("\n\nA person has an intense fear of being criticised, embarrassed or humiliated, even in everyday situations, such as speaking publicly, eating in public, being assertive at work or making small talk.\nCommon causes of social anxiety include the following:\n", 35);
                    changeColour(WHITE);
                    TypeWriter("\nThe physical symptoms that can be particularly distressing for people with social phobia include: \n -> Excessive perspiration \n -> Trembling \n -> Blushing and stammering when trying to speak. \n -> Nausea or diarrhoea \n", 35);
            }

            if (isSpecificPhobias)
            {
                changeColour(BLUE);
                TypeWriter(R"(
                      ____                  _  __ _        ____  _           _     _       
                     / ___| _ __   ___  ___(_)/ _(_) ___  |  _ \| |__   ___ | |__ (_) __ _ 
                     \___ \| '_ \ / _ \/ __| | |_| |/ __| | |_) | '_ \ / _ \| '_ \| |/ _` |
                      ___) | |_) |  __/ (__| |  _| | (__  |  __/| | | | (_) | |_) | | (_| |
                     |____/| .__/ \___|\___|_|_| |_|\___| |_|   |_| |_|\___/|_.__/|_|\__,_|
                           |_|                                                            )""\n" , 5);

                    changeColour(YELLOW);
                    LineBreak('-', 90);
                    
                    changeColour(BLUE);
                    TypeWriter("\n\nA person feels very fearful about a particular object or situation and may go to great lengths to avoid it, for example, having an injection or travelling on a plane. There are many different types of phobias.\ncommon causes of specific phobias are:\n", 35);
                    changeColour(WHITE);
                    TypeWriter("\n -> Have a persistent, excessive and unreasonable fear of a specific object, activity or situation, e.g. heights, the sight of blood or encountering a dog. \n -> Avoid situations where you may have to face the phobic stimulus, e.g. not walking down a street where there may be a dog. If the situation is unavoidable, you're likely to feel high levels of distress \n -> Find that the anxiety or avoidance associated with such situations makes it difficult to go about daily life (e.g. interferes with working, studying or seeing friends and family). \n -> The anxiety and avoidance are persistent and have been present for at least 6 months or more",35);
                    changeColour(PURPLE);
                    TypeWriter("Types of Specific Phobias: \n1. Animal type: fear that relates to animals or insects (e.g. fear of dogs or spiders). \n2.Natural environment type: fear associated with the natural environment (e.g. fear of thunder or heights). \n3. Blood/injection/injury type: fear associated with invasive medical procedures (e.g. injections), or with seeing blood or injury. \n4.Situational type: fear of specific situations (e.g. elevators, bridges or driving). \n5.Other: any other specific phobias (e.g. fear of choking, fear of vomiting).",35);

            }
            if (isPanicDisorder)
            {
                changeColour(PURPLE);
                TypeWriter(R"(
                     ____             _        ____  _                   _           
                    |  _ \ __ _ _ __ (_) ___  |  _ \(_)___  ___  _ __ __| | ___ _ __ 
                    | |_) / _` | '_ \| |/ __| | | | | / __|/ _ \| '__/ _` |/ _ \ '__|
                    |  __/ (_| | | | | | (__  | |_| | \__ \ (_) | | | (_| |  __/ |   
                    |_|   \__,_|_| |_|_|\___| |____/|_|___/\___/|_|  \__,_|\___|_|   
                                                                   )""\n" , 5);

                    changeColour(YELLOW);
                    LineBreak('-', 90);
                    
                    changeColour(BLUE);
                    TypeWriter("\n\nA person has panic attacks, which are intense, overwhelming and often uncontrollable feelings of anxiety combined with a range of physical symptoms. \nSomeone having a panic attack may experience shortness of breath, chest pain, dizziness and excessive perspiration. \nSometimes, people experiencing a panic attack think they are having a heart attack or are about to die. \nIf a person has recurrent panic attacks or persistently fears having one for more than a month, they're said to have panic disorder.  \nCommon causes of panic disorder are:\n", 35);
                    changeColour(WHITE);
                    TypeWriter("\n -> a sense of overwhelming panic or fear \n -> the thought that you are dying, choking, ‘losing control’ or ‘going mad’ \n -> increased heart rate \n -> difficulty breathing (feeling that there is not enough air) \n -> feeling choked \n -> excessive perspiration",35);

            }
            
        }
};
// optimal anxiety checker 
class AnxietyDeterminer: public mental_illness
{
    public:
    friend void emergency(int patient, int threat, string mental_health);
        void quiz() //a function that will determine how much level of anxiety user still has by taking a short quiz
        {
            showLoadingScreen(); 
            system("cls");
            changeColour(PURPLE);
            TypeWriter(R"(
                 _               _      _           ____       _                      _                 
                / \   _ __ __  _(_) ___| |_ _   _  |  _ \  ___| |_ ___ _ __ _ __ ___ (_)_ __   ___ _ __ 
               / _ \ | '_ \\ \/ / |/ _ \ __| | | | | | | |/ _ \ __/ _ \ '__| '_ ` _ \| | '_ \ / _ \ '__|
              / ___ \| | | |>  <| |  __/ |_| |_| | | |_| |  __/ ||  __/ |  | | | | | | | | | |  __/ |   
             /_/   \_\_| |_/_/\_\_|\___|\__|\__, | |____/ \___|\__\___|_|  |_| |_| |_|_|_| |_|\___|_|   
                                            |___/                                                       )""\n", 5);
            int points=0; //these points will keep adding up and depending upon the score, they will tell us the level of anxiety
            char ans; //character value either a, b or c
            
            
            changeColour(DEFAULTCOLOUR);
            TypeWriter("\n\nAnswer the following questions and we might be able to tell you whether you still experience anxiety or not. \nBelow is a list of questions that relate to life experiences common among people with anxiety disorder or GAD. \nRead each question carefully, and indicate how often you have experienced the same or similar challenges in the past few months.", 2);
            cout<<endl;
            changeColour(YELLOW);
            cout<<"\nAnswer the following questions and we might be able to tell you whether you still experience anxiety or not."<<endl;
            cout << "Q1- Do you worry about lots of different things?" << endl; //mcq quiz starts
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q2- Do you have trouble controlling your worries?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;

            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q3- Do you get irritable and/or easily annoyed when anxious?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q4- Does worry or anxiety make you feel fatigued or worn out?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q5- Does worry or anxiety interfere with falling and/or staying asleep?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q6- Does worry or anxiety make it hard to concentrate?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q7- Do you feel jumpy?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q8- Do you worry about how well you do things?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q9- Do you worry about things working out in the future?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q10- Do you worry about things that have already happened in the past?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q11- Do your muscles get tense when you are worried or anxious?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q12- Do you experience repetitive and persistent thoughts that are upsetting and unwanted?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q13- Do you experience strong fear that causes panic, shortness of breath, chest pains, a pounding heart, sweating, shaking, nausea, dizziness and/or fear of dying?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q14- Do you ever avoid places or social situation for fear of this panic?" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }

            cout << "Q15- Do you ever engage in repetitive behaviors to manage your worry? (For example, checking that the oven is off, locking doors, washing hands, counting, repeating words.)" << endl;
            cout << "\ta. " << "Never" << endl << "\tb. " << "Sometimes" << endl << "\tc. " << "Very Often" << endl;
            cin >> ans;
            if (ans == 'a')
            {
                points += 1;
            }
            if (ans == 'b')
            {
                points += 2;
            }
            if (ans == 'c')
            {
                points += 3;
            }
            
            cout<<"Your Score is: "<<points<<endl;
            //results
            if (points <= 15) //if the sum of points is less than or equal to 15
            {
                cout<<"It seems that you do not show any signs of anxiety.";
            }
            else if (points <= 30) //if the sum of points is less than or equals to 30
            {
                cout<<"It seems that you have mild indications of anxiety. Please relax and try breathing exercises to reduce it.";
            }
            else if (points <= 45) //if the sum of points is less than or equals to 45
            {
                cout<<"You show strong indications of anxiety! Please seek professional help immediately.";
                void emergency(int patient, int threat, string mental_health);
            }
        }
            

};
// menu
void Anxiety :: menu() //anxiety class calling menu function 
{
    //reference to classes
    TypesOfAnxiety Ta;
    AnxietyDeterminer anxiety2;
    int menuItem = 0, x = 9;
	bool isRunning = true;
	string goBack;
    char option;
    
    changeColour(PURPLE);
    TypeWriter(R"(
                     ___             _     __         
                    / _ | ___ __ __ (_)__ / /___ __   
                   / __ |/ _ \\ \ // / -_) __/ // /   
                  /_/ |_/_//_/_\_\/_/\__/\__/\_, /    
                                            /___/)""\n", 5);
    
    gotoXY(0, 10);
    changeColour(YELLOW);
    LineBreak('-', 95);

    gotoXY(22,9);
    changeColour(PURPLE); 
    cout << "->";
	
    
	while(isRunning)
	{
        changeColour(BLUE);
		gotoXY(24, 9);  cout << "[1] General Info";             // what is anxietyetc.
		gotoXY(24, 10); cout << "[2] Types of Anxiety";        
		gotoXY(24, 11); cout << "[3] Do You Still Experience Anxiety?";         // anxiety determiner
		gotoXY(24, 12); cout << "[4] Self Help Section";                    
		gotoXY(24, 13); cout << "Main Menu";                

		system("pause > nul"); // the > nul bit causes it the print no message, without this the cursor blinks
		
		if(GetAsyncKeyState(VK_DOWN) && x != 13) //Down-Arrow key pressed
        {
            gotoXY(22,x); 
            cout << "  ";

            x++;

            gotoXY(22,x); 
            changeColour(PURPLE);
            cout << "->";
            menuItem++;
           
            continue;
            
        }
		if(GetAsyncKeyState(VK_UP) && x != 9) // Up-Arrow key pressed
        {
            gotoXY(22,x); 
    
            cout << "  ";
            x--;
            
            gotoXY(22,x);
            changeColour(PURPLE);
            cout << "->";
            menuItem--;
            continue;
        }
			
		if(GetAsyncKeyState(VK_RETURN))
        { // Enter key pressed
			
			switch(menuItem)
            {
                case 0: // general info
                {
                    system("cls");
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(DEFAULTCOLOUR);  
                    info();

                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> goBack;
                    if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                    {
                        isRunning = false; // kills the loop;
                        system("cls");
                        menu();
                    }
                    else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for using";
                        showLoadingScreen();
                        exit(0);
                    }
                    
                    
                
                    break;
                }
                case 1: // types
                {
                    // bools used for parameters belcow
                    bool A, B, C, D;  //GAD, Social Anxiety, Specific Phobia, Panic Disorder
                    

                    system("cls");
                    changeColour(PURPLE);
                    TypeWriter(R"(
                         ______ __  __   ___    ____   ____
                        /_  __/ \ \/ /  / _ \  / __/  / __/
                         / /     \  /  / ___/ / _/   _\ \  
                        /_/      /_/  /_/    /___/  /___/)""\n" , 5);
                    
                    changeColour(YELLOW);
                    LineBreak('=',95);
                    
                    changeColour(BLUE);
                    gotoXY(24, 9);  cout << "[1] Generalized Anxiety Disorder";             
                    gotoXY(24, 10); cout << "[2] Social Anxiety";        
                    gotoXY(24, 11); cout << "[3] Specific Phobia "; 
                    gotoXY(24, 12); cout << "[4] Panic Disorder"; 
                    gotoXY(24, 13); cout << "[5] Back"; 

                    cout << "\nEnter the number to select from the above options: ";
                    cin >> option;
                    if(option == '1')
                    {
                        system("cls");
                        A = true;
                        B = false;
                        C = false;
                        D = false;

                        Ta.SelectType(A, B, C, D);

                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }

                        
                    } 
                    else if(option == '2')
                    {
                        system("cls");
                        A = false;
                        B = true;
                        C = false;
                        D = false;

                        Ta.SelectType(A, B, C, D);

                        
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                        
                    }
                    else if (option == '3')
                    {
                        system("cls");
                        A = false;
                        B = false;
                        C = true;
                        D = false;

                        Ta.SelectType(A, B, C, D);

                        changeColour(DEFAULTCOLOUR);
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                    }
                    else if (option == '4')
                    {
                        system("cls");
                        A = false;
                        B = false;
                        C = false;
                        D = true;

                        Ta.SelectType(A, B, C, D);

                        changeColour(DEFAULTCOLOUR);
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                    }
                    else if(option == '5')
                    {
                        menu();
                    }
                    else
                    {
                        changeColour(YELLOW);
                        LineBreak('_', 50);
                        showLoadingScreen();
                        changeColour(RED);
                        cout << "\nThank you for your time\n";
                    }
                     break;
                }         
                case 2: //quiz option
                {
                    system("cls");
                    
                    anxiety2.quiz();
                    changeColour(DEFAULTCOLOUR);
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> goBack;
                    if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                    {
                        isRunning = false; // kills the loop;
                        system("cls");
                        menu();
                    }
                    else if (goBack == "No" || goBack == "no" || goBack == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        LineBreak('-', 55);
                        changeColour(RED);
                        showLoadingScreen();
                        exit(0);
                    }
                    break;
                }
                case 3: // self help section
                {

                    system("cls");
                    changeColour(DEFAULTCOLOUR);
                    cout << "Welcome to self help section!\n";
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(WHITE);
                    TypeWriter(R"(
                        ____ ____ _    ____    _  _ ____ _    ___  
                        [__  |___ |    |___    |__| |___ |    |__] 
                        ___] |___ |___ |       |  | |___ |___ |)""\n", 10);

                    changeColour(YELLOW);
                    LineBreak('=',95);
                    
                    changeColour(BLUE);
                    cout << "\n\t\t\t\t[1] Breathing Exercises\n";             
                    cout << "\t\t\t\t[2] Vent\n";        
                    cout << "\t\t\t\t[3] Go Back\n"; 
                    
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(DEFAULTCOLOUR);
                    cout << "\nEnter the number to select from the above options, or press anyother key to exit: ";
                    cin >> option;
                    if(option == '1')
                    {
                        system("cls");
                        exercises();

                    }
                    else if (option == '2')
                    {
                        system("cls");
                        gotoXY(0, 0);
                        vent();
                        
                    }
                    else if (option == '3')
                    {
                        system("cls");
                        menu();
                    }
                    
                    break;
                }  
                case '4': //back to main
                {
                    system("cls");
                    Main();
                    break;
                }
                default:
                { 
                    break;
                }
            }		
		
        }

    }
}
//Subclass END: Anxiety

//Subclass: OCD
class OCD : public mental_illness
{
    private:
        char select;
        
    public:
        
        void menu();
        void info()
        {
            TypeWriter("\nObsessive-compulsive disorder (OCD) is a disorder in which people have recurring, unwanted thoughts, ideas or sensations (obsessions) that make them feel driven to do something repetitively (compulsions). The repetitive behaviors, such as hand washing, checking on things or cleaning, can significantly interfere with a person�s daily activities and social interactions..\n", 35);
            changeColour(YELLOW);      
            LineBreak('=', 95);
            changeColour(PURPLE);        
            TypeWriter(R"(                    
 __             __  ___  __         __  
/__` \ /  |\/| |__)  |  /  \  |\/| /__` 
.__/  |   |  | |     |  \__/  |  | .__/ 
----------------------------------------)""\n", 1);

            changeColour(DEFAULTCOLOUR);
            TypeWriter("\nOCD is the main symptom of several conditions, including:\n \n\tFear of contamination or dirt. \n\tDoubting and having difficulty tolerating uncertainty.\n\tNeeding things orderly and symmetrical.\n\tAggressive or horrific thoughts about losing control and harming yourself or others", 35);



            changeColour(YELLOW);    
            LineBreak('=', 95);
        }
        void SelectType(bool isGOD, bool isChecking, bool isContamination, bool isRuminationsandintrusivethoughts)     // TYPES OF OCD: 
        {
            if(isGOD)
            {
                changeColour(RED);
                TypeWriter(R"(  
	____			                     _                   _    ____    _____  _____  
  / ____|                               | |(_)              | |  / __ \  / ____||  __ \ 
 | |  __   ___  _ __    ___  _ __  __ _ | | _  ____ ___   __| | | |  | || |     | |  | |
 | | |_ | / _ \| '_ \  / _ \| '__|/ _` || || ||_  // _ \ / _` | | |  | || |     | |  | |
 | |__| ||  __/| | | ||  __/| |  | (_| || || | / /|  __/| (_| | | |__| || |____ | |__| |
  \_____| \___||_| |_| \___||_|   \__,_||_||_|/___|\___| \__,_|  \____/  \_____||_____/ 
                                                                                        
                                                                                         )""\n" , 5);


                    changeColour(YELLOW);
                    LineBreak('-', 90);

                    changeColour(BLUE);
                    TypeWriter("\n\nOCD isn�t about habits like biting your nails or thinking negative thoughts. An obsessive thought might be that certain numbers or colors are �good� or �bad.� A compulsive habit might be to wash your hands seven times after touching something that could be dirty. Although you may not want to think or do these things, you feel powerless to stop.\nSome common causes of GAD are as follows: \n" , 35);
                    changeColour(WHITE);
            }
            
            if(isChecking)
            {
                changeColour(GREEN);
                TypeWriter(R"(             
    ____  _                  _     _
  / ____|| |                | |   (_)              
 | |     | |__    ___   ___ | | __ _  _ __    __ _ 
 | |     | '_ \  / _ \ / __|| |/ /| || '_ \  / _` |
 | |____ | | | ||  __/| (__ |   < | || | | || (_| |
  \_____||_| |_| \___| \___||_|\_\|_||_| |_| \__, |
                                              __/ |
                                             |___/  )""\n" ,5);


                    changeColour(YELLOW);
                    LineBreak('-', 90);
                    
                    changeColour(BLUE);
                    TypeWriter("\n\nChecking, such as locks, alarm systems, ovens, or light switches, or thinking you have a medical condition like pregnancy or schizophrenia.\n", 35);
            }

            if (isContamination)
            {
                changeColour(BLUE);
                TypeWriter(R"(
                
   _____               _                     _                _    _                    
  / ____|             | |                   (_)              | |  (_)                   
 | |      ___   _ __  | |_  __ _  _ __ ___   _  _ __    __ _ | |_  _   ___   _ __   ___ 
 | |     / _ \ | '_ \ | __|/ _` || '_ ` _ \ | || '_ \  / _` || __|| | / _ \ | '_ \ / __|
 | |____| (_) || | | || |_| (_| || | | | | || || | | || (_| || |_ | || (_) || | | |\__ \
  \_____|\___/ |_| |_| \__|\__,_||_| |_| |_||_||_| |_| \__,_| \__||_| \___/ |_| |_||___/
                                                                                    )""\n" , 5);

                    changeColour(YELLOW);
                    LineBreak('-', 90);
                    
                    changeColour(BLUE);
                    TypeWriter("\n\nContamination, a fear of things that might be dirty or a compulsion to clean. Mental contamination involves feeling like you�ve been treated like dirt.\n", 35);
            }
            if (isRuminationsandintrusivethoughts)
            {
                changeColour(PURPLE);
                TypeWriter(R"(
  _____                    _                _    _                    
 |  __ \                  (_)              | |  (_)                   
 | |__) |_   _  _ __ ___   _  _ __    __ _ | |_  _   ___   _ __   ___ 
 |  _  /| | | || '_ ` _ \ | || '_ \  / _` || __|| | / _ \ | '_ \ / __|
 | | \ \| |_| || | | | | || || | | || (_| || |_ | || (_) || | | |\__ \
 |_|  \_\\__,_||_| |_| |_||_||_| |_| \__,_| \__||_| \___/ |_| |_||___/
                                                                      
                                                                        )""\n" , 5);

                    changeColour(YELLOW);
                    LineBreak('-', 90);
                    
                    changeColour(BLUE);
                    TypeWriter("\n\nRuminations and intrusive thoughts, an obsession with a line of thought. Some of these thoughts might be violent or disturbing.\n", 35);
            }
            
        }
        void exercises()
        {
            char selc;
            string back;

            showLoadingScreen();
            system("cls");
            changeColour(GREEN);
            TypeWriter(R"(
                ___  ____ ____ ____ ___ _  _ _ _  _ ____    ____ _  _ ____ ____ ____ _ ____ ____ ____ 
                |__] |__/ |___ |__|  |  |__| | |\ | | __    |___  \/  |___ |__/ |    | [__  |___ [__  
                |__] |  \ |___ |  |  |  |  | | | \| |__]    |___ _/\_ |___ |  \ |___ | ___] |___ ___] )""\n", 3);

            changeColour(YELLOW);
            LineBreak('=', 119);

            changeColour(BLUE);
            gotoXY(24, 9);  cout << "[1] 4-7-8 breathing technique";             
            gotoXY(24, 10); cout << "[2] Three-part breathing";        
            gotoXY(24, 11); cout << "[3] Box breathing";
            gotoXY(24, 12); cout << "[4] Go Back";

            changeColour(DEFAULTCOLOUR);
            cout << "\nEnter the number to select from the above exercises: ";
            cin >> selc;
            switch (selc)
            {
                case '1':
                {   
                    changeColour(WHITE);
                    cout << "\n Here’s how to practice the 4-7-8 breathing technique:\n\n";
                    changeColour(PURPLE);
                    TypeWriter("1. Allow your lips to gently part.\n2. Exhale completely, making a breathy whoosh sound as you do.\n3. Press your lips together as you silently inhale through the nose for a count of 4 seconds.\n4. Hold your breath for a count of 7.\n5. Exhale again for a full 8 seconds, making a whooshing sound throughout.\n6. Repeat 4 times when you first start. Eventually work up to 8 repetitions.""\n" , 30);

                    invalid:
                    cout << "\n\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        system("cls");
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid;
                    }
                    
                    break;
                }
                case '2':
                {
                    changeColour(WHITE);
                    cout << "\nTo practice the three-part breathing exercise, follow these three steps:\n\n";
                    changeColour(PURPLE);
                    TypeWriter("\n1. Take a long, deep inhale.\n2. Exhale fully while focusing intently on your body and how it feels.\n3. After doing this a few times, slow down your exhale so that it’s twice as long as your inhale.", 30);

                    invalid1:
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid1;
                    }

                    break;
                }
                case '3':
                {
                    changeColour(WHITE);
                    cout << "\nDuring box breathing, you want to focus intently on the oxygen you’re bringing in and pushing out::\n\n";
                    changeColour(PURPLE);
                    TypeWriter("\n1. Sit with your back straight, breathe in, and then try to push all the air out of your lungs as you exhale.\n2. Inhale slowly through your nose and count to 4 in your head, filling your lungs with more air with each number.\n3. Hold your breath and count to 4 in your head.\n4. Slowly exhale through your mouth, focusing on getting all the oxygen out of your lungs.", 30);

                    changeColour(WHITE);
                    TypeWriter("\tBox breathing is a common technique during meditation, a very popular method of finding mental focus and relaxing. Meditation has a variety of known benefits for your overall health.", 50);

                    invalid2:
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> back;
                    if (back == "Yes"|| back == "yes" || back == "YES")
                    {
                        system("cls");
                        menu();
                    }
                    else if (back == "No"|| back == "no" || back == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        showLoadingScreen();
                        exit(0);
                    }
                    else
                    {
                        showLoadingScreen();
                        goto invalid2;
                    }
                    break;
                }
                case '4':
                {
                    menu();
                    break;
                }
                default:
                { 
                    break;
                }

            }
        }
};
// menu
void OCD :: menu()
{
    
    OCD Determiner ;
    int menuItem = 0, x = 9;
	bool isRunning = true;
	string goBack;
    char option;
    
    changeColour(PURPLE);
    TypeWriter(R"(
                     ____   _____ _____  
                    / __ \ / ____|  __ \ 
                   | |  | | |    | |  | |
                   | |  | | |    | |  | |
                   | |__| | |____| |__| |
                    \____/ \_____|_____/  )""\n", 5);
    
    gotoXY(0, 8);
    changeColour(YELLOW);
    LineBreak('-', 95);

    gotoXY(22,9);
    changeColour(PURPLE); 
    cout << "->";
	
    
	while(isRunning)
	{
        changeColour(BLUE);
		gotoXY(24, 9);  cout << "[1] General Info";                                 // what is OCD
		gotoXY(24, 10); cout << "[2] Types of OCD";        
		gotoXY(24, 11); cout << "[3] *ADD A UNIQUE FUNCTION FOR OCD HERE*";         // OCD determiner
		gotoXY(24, 12); cout << "[4] Self Help Section";                    
		gotoXY(24, 13); cout << "Main Menu";                

		system("pause > nul"); // the > nul bit causes it the print no message, without this the cursor blinks
		
		if(GetAsyncKeyState(VK_DOWN) && x != 13) //Down-Arrow key pressed
        {
            gotoXY(22,x); 
            cout << "  ";

            x++;

            gotoXY(22,x); 
            changeColour(PURPLE);
            cout << "->";
            menuItem++;
           
            continue;
            
        }
		if(GetAsyncKeyState(VK_UP) && x != 9) // Up-Arrow key pressed
        {
            gotoXY(22,x); 
    
            cout << "  ";
            x--;
            
            gotoXY(22,x);
            changeColour(PURPLE);
            cout << "->";
            menuItem--;
            continue;
        }
			
		if(GetAsyncKeyState(VK_RETURN))
        { // Enter key pressed
			
			switch(menuItem)
            {
                case 0: // general info
                {
                    system("cls");
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(DEFAULTCOLOUR);  
                    info();

                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> goBack;
                    if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                    {
                        isRunning = false; // kills the loop;
                        system("cls");
                        menu();
                    }
                    else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for using";
                        showLoadingScreen();
                        exit(0);
                    }
                    
                    
                
                    break;
                }
                case 1: // types
                {
                    // bools used for parameters belcow
                    bool A, B , C, D;  //GOD, Checking, Contamination, Ruminations
                    

                    system("cls");
                    changeColour(PURPLE);
                    TypeWriter(R"(
                         ______ __  __   ___    ____   ____
                        /_  __/ \ \/ /  / _ \  / __/  / __/
                         / /     \  /  / ___/ / _/   _\ \  
                        /_/      /_/  /_/    /___/  /___/)""\n" , 5);
                    
                    changeColour(YELLOW);
                    LineBreak('=',95);
                    
                    changeColour(BLUE);
                    gotoXY(24, 9);  cout << "[1] Generalized OCD";             
                    gotoXY(24, 10); cout << "[2] Checking";        
                    gotoXY(24, 11); cout << "[3] Ruminations"; 
                    gotoXY(24, 12); cout << "[4] Panic Disorder"; 
                    gotoXY(24, 13); cout << "[5] Back"; 

                    cout << "\nEnter the number to select from the above options: ";
                    cin >> option;
                    if(option == '1')
                    {
                        system("cls");
                        A = true;
                        B = false;
                        C = false;
                        D = false;

                        SelectType(A, B, C, D);

                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }

                        
                    } 
                    else if(option == '2')
                    {
                        system("cls");
                        A = false;
                        B = true;
                        C = false;
                        D = false;

                        SelectType(A, B, C, D);

                        
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                        
                    }
                    else if (option == '3')
                    {
                        system("cls");
                        A = false;
                        B = false;
                        C = true;
                        D = false;

                        SelectType(A, B, C, D);

                        changeColour(DEFAULTCOLOUR);
                        cout << "\nDo you want to go back? (Yes / No): ";
                        cin >> goBack;
                        if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                        {
                            isRunning = false; // kills the loop;
                            system("cls");
                            menu();
                        }
                        else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                        {
                            changeColour(YELLOW);
                            LineBreak('-', 55);
                            changeColour(RED);
                            cout << "Thank you for your time";
                            showLoadingScreen();
                            exit(0);
                        }
                        else if (option == '4')
                        {
                            system("cls");
                            A = false;
                            B = false;
                            C = false;
                            D = true;

                            SelectType(A, B, C, D);

                            changeColour(DEFAULTCOLOUR);
                            cout << "\nDo you want to go back? (Yes / No): ";
                            cin >> goBack;
                            if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                            {
                                isRunning = false; // kills the loop;
                                system("cls");
                                menu();
                            }
                            else if (goBack == "No"|| goBack == "no" || goBack == "NO")
                            {
                                changeColour(YELLOW);
                                LineBreak('-', 55);
                                changeColour(RED);
                                cout << "Thank you for your time";
                                showLoadingScreen();
                                exit(0);
                            }
                        }
                        else if(option == '5')
                        {
                            menu();
                        }
                        else
                        {
                            changeColour(YELLOW);
                            LineBreak('_', 50);
                            showLoadingScreen();
                            changeColour(RED);
                            cout << "\nThank you for your time\n";
                            
                        }
                        
                        break;
                    }
                }
                case 2: //a unique function for OCD
                {
                    system("cls");
                    
                    
                    changeColour(DEFAULTCOLOUR);
                    cout << "\nDo you want to go back? (Yes / No): ";
                    cin >> goBack;
                    if (goBack == "Yes"|| goBack == "yes" || goBack == "YES")
                    {
                        isRunning = false; // kills the loop;
                        system("cls");
                        menu();
                    }
                    else if (goBack == "No" || goBack == "no" || goBack == "NO")
                    {
                        changeColour(YELLOW);
                        LineBreak('-', 55);
                        changeColour(RED);
                        cout << "Thank you for your time";
                        LineBreak('-', 55);
                        changeColour(RED);
                        showLoadingScreen();
                        exit(0);
                    }
                    break;
                }
                case 3: // self help
                {

                    system("cls");
                    changeColour(DEFAULTCOLOUR);
                    cout << "Welcome to self help section!\n";
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(WHITE);
                    TypeWriter(R"(
                        ____ ____ _    ____    _  _ ____ _    ___  
                        [__  |___ |    |___    |__| |___ |    |__] 
                        ___] |___ |___ |       |  | |___ |___ |)""\n", 10);

                    changeColour(YELLOW);
                    LineBreak('=',95);
                    
                    changeColour(BLUE);
                    cout << "\n\t\t\t\t[1] Breathing Exercises\n";             
                    cout << "\t\t\t\t[2] Vent\n";        
                    cout << "\t\t\t\t[3] Go Back\n"; 
                    
                    changeColour(YELLOW);
                    LineBreak('=',95);

                    changeColour(DEFAULTCOLOUR);
                    cout << "\nEnter the number to select from the above options, or press anyother key to exit: ";
                    cin >> option;
                    if(option == '1')
                    {
                        system("cls");
                        exercises();

                    }
                    else if (option == '2')
                    {
                        system("cls");
                        gotoXY(0, 0);
                        vent();
                        
                    }
                    else if (option == '3')
                    {
                        system("cls");
                        menu();
                    }
                    
                    break;
                }  
                case '4':
                {
                    system("cls");
                    Main(); //back to main menu
                    break;
                }
                default:
                { 
                    break;
                }

            }		
		
        }

    }
}
//Subclass END: OCD

//Subclass: ADHD
class ADHD :public mental_illness {
	int choice;//to store users choice
public:
	friend void emergency(int patient, int threat, string mental_health);
	void menu() 
	{
		//main menu for ADHD subclass
		showLoadingScreen();
		system("cls");
		quicken();
		changeColour(BLUE);
		//cout ascii art title
		std::cout << R"(
    ___    ____  __  ______                                                               
   /   |  / __ \/ / / / __ \                                                              
  / /| | / / / / /_/ / / / /                                                              
 / ___ |/ /_/ / __  / /_/ /                                                               
/_/  |_/_____/_/ /_/_____/                                                                
)";
		TypeWriter("Welcome to the ADHD Self-help Section. Please choose one of the following to get started.\n\t1. Advice\n\t2. Vent\n\t3. Exercises\n\t4. Contact Therapists\n\t5. Medications\n\t6. Go back to Main Menu\n", 60);
	Invalid_Entry:
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			self_help_advice();
			//goes to self help function 
			break;
		case 2:
			system("cls");
			vent();
			//vent() function in base class
			break;
		case 3:
			system("cls");
			exercises();
			//exercise function
			break;
		case 4:
			system("cls");
			contact_therapists();
			break;
		case 5:
			system("cls");
			medications();
			break;
		case 6:
			TypeWriter("Thank you for your time. Stay safe.", 60);
            system("cls");
            Main();
			break;
		default:
			changeColour(RED);
			cout << "INVALID ENTRY. PLEASE TRY AGAIN: ";
			changeColour(BLUE);
			goto Invalid_Entry;
			break;
		}
	}
	void exercises() 
	{
		//exercises related to ADHD
		system("cls");
		changeColour(BLUE);
		int option;//for any number option
		int time;//for entering time 
		string text;//for any textual data
		std::cout << R"(
    ______                    _               
   / ____/  _____  __________(_)_______  _____
  / __/ | |/_/ _ \/ ___/ ___/ / ___/ _ \/ ___/
 / /____>  </  __/ /  / /__/ (__  )  __(__  ) 
/_____/_/|_|\___/_/   \___/_/____/\___/____/  
                                              
)";
		//ascii font 
		TypeWriter("If you have ADHD, a workout does more than make you feel good. It can help control your symptoms, too.\n\n", 60);
		TypeWriter("Here are some options that might help you out with exercising:\n\t1. Workout Advice\n\t2. Excercises \n\t3. How to stay motivated \n\t4. Go to Menu\n\t5. Meditate", 60);
	Exercise:
		//choosing an option from the above mentioned list 
		TypeWriter("\nChoose an option : ", 60);
		cin >> option;
		switch (option)
		{
		case 1:
		{
			changeColour(YELLOW);
			TypeWriter("How often do you exercise in a day? (time in minutes)\n", 60);
			//gives adive depending upon the activity time of user
			cin >> time;
			if (time >= 30)//if time is greater that 30 minutes
			{
				TypeWriter("That's great! The effects of exercise only last for so long, just like medicine. Think of your workout as a treatment dose.", 60);
			}
			else if (time <= 15 || time >= 25)//if time is less than 25 and greater than 15
			{
				TypeWriter("Keep it up! The exercise you choose is up to you, but make sure it's moderately intense.Even a single session of moving your body can make you\n more motivated for mental tasks, increase your brainpower, give you energy, and help you feel less confused. ", 60);
			}
			else if (time < 10)//if time is less than 10 minutes
			{
				TypeWriter("Aim for at least one 30- to 40-minute activity a day, 4 or 5 days a week. To reap these rewards, though, you need to exercise \nthe right way and the right amount. The key is to find an activity that fits your lifestyle and then stick with it.", 60);
			}
			TypeWriter("Beyond helping with ADHD symptoms, exercise has several other benefits. Getting regular workouts can help you:\n\t- Stay at a healthy weight.That's important because evidence suggests that people with ADHD are more likely to become obese.\n\t- Reduce your risk of heart disease, diabetes, and certain types of cancer.\n\t- Keep your blood pressure and cholesterol levels in a normal range.\n\t- Strengthen your bones.\n\t- Improve your mood and self - esteem.", 60);
			//general advice
			system("pause");
			goto Exercise;
		}
		case 2:
		{
			//switch case for different types of excercises or routines to follow
			changeColour(YELLOW);
			TypeWriter("Here are some options that might help you out with exercising:\n\t1. Aerobic Exercise\n\t2. Martial Arts \n\t3. Strength Training\n\t4. Other Complex Exercises\n\t5. Go back to Exercise Menu", 60);
		EX:
			TypeWriter("\nChoose an option : ", 60);
			cin >> option;
			if (option == 1)//chhoosing aerobic exercises
			{
				changeColour(GREEN);
				TypeWriter("This is anything that gets your heart pounding. You want to do something that raises your heart rate and keeps it there for a set amount of time, \nlike half an hour to 40 minutes.", 60);
				TypeWriter("You can try one of these:\n\t- Running\n\t- Walking briskly\n\t- Biking\n\t- Swimming laps\n", 60);
				goto EX;
			}
			else if (option == 2)//choosing Martial Arts
			{
				changeColour(BLUE);
				TypeWriter("Experts say the more complex your exercise is, the better for your brain. Sports like karate, \ntaekwondo, jiujitsu, and judo focus on self-control and bringing together your mind and body.", 60);
				TypeWriter("When you do martial arts, you get training in skills like:\n\t- Focus and concentration\n\t- Balance\n\t- Timing\n\t- Memory\n\t- Consequences of actions\n\t- Fine motor skills", 60);
				goto EX;
			}
			else if (option == 3)//choosing Strength Training as option
			{
				changeColour(RED);
				TypeWriter("If you're only just starting out with exercise, go for aerobic activities like walking or \njogging at first. After you've been at it for a while, add in some strength work for variety. Try exercises like:", 60);
				TypeWriter("\n\t- Lunges\n\t- Squats\n\t- Pushups\n\t- Pullups\n\t- Weightlifting\n", 60);
				goto EX;
			}
			else if (option == 4)//choosing Other Complex Exercises as an option
			{
				changeColour(PURPLE);
				TypeWriter("If martial arts isn't your thing, other physical activities that also challenge your mind and body are:\n\t- Rock climbing\n\t- Dance\n\t- Gymnastics\n\t- Yoga\n", 60);
				changeColour(YELLOW);
				TypeWriter("\nTEAM SPORTS:\n\n\tIf you join a softball or soccer league, it may be just the thing to get you up and moving \n\tseveral times a week. Organized sports have all the benefits of physical exercise with the added bonus of a social group to motivate you.\n", 60);
				goto EX;
			}
			else if (option == 5)
			{
				exercises();//goes back to exercise function while clearing the screen
			}
			else
			{
				TypeWriter("\nINVALID ENTRY! PLEASE TRY AGAIN", 60);
				goto EX;
			}
			TypeWriter("\nWould you like to go back to Exercises menu?\n", 60);
			cin >> text;
			if (text == "YES" || text == "Yes" || text == "yes")
			{
				menu();
			}
			else goto Exercise;
		}
		case 3:
		{
			//case for advice related to saying motivated
			changeColour(YELLOW);
			TypeWriter("Just like medicine, exercise only helps you treat ADHD if you keep it up. But if you have problems with attention span, how do you stay the course? Try these tips:\n\t1. Keep it interesting\n\t2. Find a partner\n\t3. Move in the morning\n\t4. Maintain meds\n\t5. Goto Exercise Menu\n", 60);
		motivation:
			//choosing options repeatedly
			cin >> option;
			if (option == 1)
			{
				changeColour(PURPLE);
				TypeWriter("\nKeep it interesting:\n\n\tSwitch up the type of exercise.You can stay out of a rut if you change your activity every day or week.", 60);
				goto motivation;
			}
			else if (option == 2)
			{
				changeColour(RED);
				TypeWriter("\nFind a partner:\n\n\tA workout buddy can help you stay on track and help pass the time while you sweat.", 60);
				goto motivation;
			}
			else if (option == 3)
			{
				changeColour(BLUE);
				TypeWriter("\nMove in the morning:\n\n\tIf it fits in your schedule, exercise first thing in the morning before you take your medication. \nThat way, you'll get the most benefit from all the extra mood-boosting chemicals in your body.", 60);
				goto motivation;
			}
			else if (option == 4)
			{
				changeColour(PURPLE);
				TypeWriter("\nMaintain meds:\n\n\tExercise can give you a huge leg up on your ADHD symptoms, but it doesn't \nreplace your medication. Don't stop your other treatments unless your doctor says it's OK.", 60);
				goto motivation;
			}
			else
			{
				TypeWriter("\nINVALID ENTRY! PLEASE TRY AGAIN", 60);
				goto motivation;
			}

			exercises();
		}
		//switch case ends here 
		}
	}
	//exercise function ends here

	void self_help_advice() {
		system("cls");
		changeColour(BLUE);
		std::cout << R"(
   _____      ______   __  __     __         ___       __      _         
  / ___/___  / / __/  / / / /__  / /___     /   | ____/ /   __(_)_______ 
  \__ \/ _ \/ / /_   / /_/ / _ \/ / __ \   / /| |/ __  / | / / / ___/ _ \
 ___/ /  __/ / __/  / __  /  __/ / /_/ /  / ___ / /_/ /| |/ / / /__/  __/
/____/\___/_/_/    /_/ /_/\___/_/ .___/  /_/  |_\__,_/ |___/_/\___/\___/ 
                               /_/                                       
)";
		int option;
		TypeWriter("If you have ADHD, you know it can make you feel misunderstood and frustrated at times. But it doesn't have to hold you back. Instead, learn as much as you can about it.\n\nThere's no quick fix for ADHD. But working with doctors and therapists can help you figure out how to be and do your best, both in school and socially. It's important to treat ADHD. That might mean taking medicine or working with a therapist — most people with ADHD do both.\n", 60);
		TypeWriter("Here are a couple of advice that might help you along the way:\n\t1. To help concentrating\n\t2. To stay organized\n\t3. Let people around you know\n\t4. Exercise Frequently\n\t5. Meditate", 60);
	ADVICE:
		//gives advice according to the option selected
		TypeWriter("\nChoose an option : ", 60);
		cin >> option;
		if (option == 1)
		{
			TypeWriter("Do you have trouble concentrating?\n", 60);
			TypeWriter("\t- Turn off your phone when doing any kind of work.\n\tSit in the front of class or a crowd to limit distractions.\n", 60);
			goto ADVICE;
		}
		else if (option == 2)
		{
			TypeWriter("To stay organized use tools that help you stay organized.\n\t- Keep track of assignments in a homework notebook or on a phone organization app.\n\t- List the books and assigned readings you'll need to bring home.\n\t- Set phone reminders for classes and other appointments, or write them down in a planner.\n", 60);
			goto ADVICE;
		}
		else if (option == 3)
		{
			TypeWriter("Let friends know what's going on. Sometimes we blurt things out and regret it later on. Or we do silly, impulsive things.\n\t- If this happens to you, let your friends know that sometimes you say things without thinking them through.\n\t- Apologize if you have hurt someone's feelings and try to be extra careful in new situations.\n", 60);
			goto ADVICE;
		}
		else if (option == 4)
		{
			TypeWriter("Get plenty of exercise.\n\t- Exercise can help people who have ADHD.\n\t- If you feel hyper during school or work, talk to a teacher or family member about taking activity breaks so you can stay focused and concentrate better when in class or during work.\n\t- Take activity breaks often while studying or doing work.\n", 60);
			goto ADVICE;
		}
		else if (option == 5)
		{
			TypeWriter("Practice relaxation and meditation.\n\t- Following a regular meditation and mindfulness practice helps people train their attention and focus better. \n\t- Meditation can lower stress reactions too.\n", 60);
			goto ADVICE;
		}
		else
		{
			TypeWriter("\nINVALID ENTRY! PLEASE TRY AGAIN", 60);
			goto ADVICE;
		}
		menu();
	}
	//self help advice function ends here

	void contact_therapists() {
		//this member function provides a list of therapists in Islamabad according to the patients preference in case they wish to seek professional help
		system("cls");
		changeColour(WHITE);
		std::cout << R"(
   ______            __             __     ________                          _      __ 
  / ____/___  ____  / /_____ ______/ /_   /_  __/ /_  ___  _________ _____  (_)____/ /_
 / /   / __ \/ __ \/ __/ __ `/ ___/ __/    / / / __ \/ _ \/ ___/ __ `/ __ \/ / ___/ __/
/ /___/ /_/ / / / / /_/ /_/ / /__/ /_     / / / / / /  __/ /  / /_/ / /_/ / (__  ) /_  
\____/\____/_/ /_/\__/\__,_/\___/\__/    /_/ /_/ /_/\___/_/   \__,_/ .___/_/____/\__/  
                                                                  /_/                  
)";
		quicken();
		char preference;
		string ans;
		cout << "\nHi " << name << ", we're glad you are contacting professional help. Based on your preferences, we will provide a list of therapists in Islamabad you can contact for depression.\n\t Would you like a male therapist, female therapist, or do you have no preference? (enter M, F or N)\n";
	InvalidEntry:
		cin >> preference;//take gender preference as input.
		if (preference == 'M')
		{
			if (age >= 10)//if they are adolescents/adults/elderly
			{
				changeColour(BLUE);
				TypeWriter("\n1. Dr Mohamad Mehdi Badiei (Licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Child and Adolescent Services\n\t- Mediation\nSCOPE:\n\t- Adolescent Counselling\n\t- Anxiety Disorders\n\t- Attention Deficit Disorders\n\t- Bipolar Mood Disorders\n\t- Depression\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\n\t- Farsi\nFEES: Direct payment\n\nCONTACT:\n\t- 03218872033\n\n", 60);
				TypeWriter("Go back to main menu?\n", 60);
				cin >> ans;
				if (ans == "YES" || ans == "Yes" || ans == "yes")
				{
					menu();
				}
				else abort;
			}
			else if (age < 10)//if they are children.
			{
				TypeWriter("\n1. Dr Mohamad Mehdi Badiei (Licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Child and Adolescent Services\n\t- Mediation\nSCOPE:\n\t- Adolescent Counselling\n\t- Anxiety Disorders\n\t- Attention Deficit Disorders\n\t- Bipolar Mood Disorders\n\t- Depression\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\n\t- Farsi\nFEES: Direct payment\n\nCONTACT:\n\t- 03218872033\n\n", 60);
				TypeWriter("Go back to main menu?\n", 60);
				cin >> ans;
				if (ans == "YES" || ans == "Yes" || ans == "yes")
				{
					menu();
				}
				else abort;
			}
		}
		else if (preference == 'F') {
			if (age >= 10)//if they are adolescents/adults/elderly
			{
				changeColour(BLUE);
				TypeWriter("\n1. Miss Syeda Hadia Qudrat (Licensed clinical psychologist).\nSERVICES:\n\t- Art Therapy\n\t- Assessment\n\t- Counselling (Career/ Family)\n\t- Psychotherapy\nSCOPE:\n\t- Adolescent Counselling\n\t- Attention Deficit Disorders\n\t- Autism and Developmental Difficulty\n\t- Behavioural and Emotional Problems\n\t- Body Image\n\t- Obsessions and Compulsions (OCD)\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\n\t- Turkish\nFEES: Direct payment\n\nCONTACT:\n\t- 03335731403\n\n", 60);
				changeColour(YELLOW);
				TypeWriter("2. Mrs Aisha Khan (Clinical Psychologist)\nSERVICES:\n\t- Assessment(Personality)\n\t-Psychotherapy (CBT)\n\t- Counselling\nSCOPE:\n\t- Anger Management Issues\n\t- Attention Deficit Disorders\n\t- Anxiety Disorders\n\t- Behavioral and Emotional Problems\n\t- Depression\nFLUENCY:\n\t- FLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Please inquire.\nCONTACT:\n\t- 03310143790\n", 60);
				TypeWriter("Go back to main menu?\n", 60);
				cin >> ans;
				if (ans == "YES" || ans == "Yes" || ans == "yes")
				{
					menu();
				}
				else abort;
			}
			else if (age < 10)//if they are children.
			{
				TypeWriter("\n1. Miss Syeda Hadia Qudrat (Licensed clinical psychologist).\nSERVICES:\n\t- Art Therapy\n\t- Assessment\n\t- Counselling (Career/ Family)\n\t- Psychotherapy\nSCOPE:\n\t- Adolescent Counselling\n\t- Attention Deficit Disorders\n\t- Autism and Developmental Difficulty\n\t- Behavioural and Emotional Problems\n\t- Body Image\n\tObsessions and Compulsions (OCD)\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\n\t- Turkish\nFEES: Direct payment\n\nCONTACT:\n\t- 03335731403\n\n", 60);
				TypeWriter("Go back to main menu?\n", 60);
				cin >> ans;
				if (ans == "YES" || ans == "Yes" || ans == "yes")
				{
					menu();
				}
				else abort;
			}
		}
		else if (preference == 'N')//for no preference of gender
		{
			TypeWriter("List of Therapists you can contact for ADHD for all ages:\n", 60);
			changeColour(BLUE);
			TypeWriter("\n1. Dr Mohamad Mehdi Badiei (Licensed psychologist).\nSERVICES:\n\t- Consultation\n\t- Child and Adolescent Services\n\t- Mediation\nSCOPE:\n\t- Adolescent Counselling\n\t- Anxiety Disorders\n\t- Attention Deficit Disorders\n\t- Bipolar Mood Disorders\n\t- Depression\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\n\t- Farsi\nFEES: Direct payment\n\nCONTACT:\n\t- 03218872033\n\n", 60);
			changeColour(RED);
			TypeWriter("\n2. Miss Syeda Hadia Qudrat (Licensed clinical psychologist).\nSERVICES:\n\t- Art Therapy\n\t- Assessment\n\t- Counselling (Career/ Family)\n\t- Psychotherapy\nSCOPE:\n\t- Adolescent Counselling\n\t- Attention Deficit Disorders\n\t- Autism and Developmental Difficulty\n\t- Behavioural and Emotional Problems\n\t- Body Image\n\t- Obsessions and Compulsions (OCD)\nFLUENCY:\n\t- Urdu/Hindi\n\t- English\n\t- Turkish\nFEES: Direct payment\n\nCONTACT:\n\t- 03335731403\n\n", 60);
			changeColour(YELLOW);
			TypeWriter("\n3. Mrs Aisha Khan (Clinical Psychologist)\nSERVICES:\n\t- Assessment(Personality)\n\t-Psychotherapy (CBT)\n\t- Counselling\nSCOPE:\n\t- Anger Management Issues\n\t- Attention Deficit Disorders\n\t- Anxiety Disorders\n\t- Behavioral and Emotional Problems\n\t- Depression\nFLUENCY:\n\t- FLUENCY:\n\t- Urdu/Hindi\n\t- English\nFEES: Please inquire.\nCONTACT:\n\t- 03310143790\n", 60);
			TypeWriter("Go back to main menu?\n", 60);
			cin >> ans;
			if (ans == "YES" || ans == "Yes" || ans == "yes")
			{
				menu();
			}
			else abort;
		}
		else
		{
			cout << "INVALID ENTRY> PLEASE TRY AGAIN: ";
			goto InvalidEntry;
		}
		menu();
	}
	//contact therapist function ends here

	void medications() {
		//to provide information on commonly used medication types for ADHD
		system("cls");
		changeColour(PURPLE);
		std::cout << R"(
    __  ___         ___            __  _           
   /  |/  /__  ____/ (_)________ _/ /_(_)___  ____ 
  / /|_/ / _ \/ __  / / ___/ __ `/ __/ / __ \/ __ \
 / /  / /  __/ /_/ / / /__/ /_/ / /_/ / /_/ / / / /
/_/  /_/\___/\__,_/_/\___/\__,_/\__/_/\____/_/ /_/ 
                                                   
)";
		TypeWriter("\n(DO NOT TAKE THESE MEDICATIONS WITHOUT SEEKING PROFESSIONAL HELP FIRST.)\n", 60);
		changeColour(BLUE);
		TypeWriter("\nYour healthcare provider may prescribe:\n\t1. Stimulant Medication\n\t2. Non-Stimulant Medication\nEnter a number to get more intel on the specified medication type: ", 60);
		meds:
		//choosing meds repeatedly
		cin >> choice;
		if (choice == 1)
		{
			changeColour(YELLOW);
			TypeWriter("\nDexmethylphenidate Stimulant:\nThis medication is used to treat attention deficit hyperactivity disorder. It works by changing the amounts of certain natural substances in the brain. It belongs to a class of drugs known as stimulants.\nCommon side effects of this drug include:\n\tNausea\n\tNervousness\n\tTrouble sleeping\n\tHeadache\n\tStomach pain\n\tLoss of appetite\n\n Note: This medication may raise your blood pressure. Check your blood pressure regularly and tell your doctor if the results are high.\n", 60);
			goto meds;
		}
		else if (choice == 2)
		{
			changeColour(RED);
			TypeWriter("\nAtomoxetine:\nIt is used as part of a total treatment plan, including psychological, social, and other treatments. It may help to increase the ability to pay attention, concentrate, stay focused, and stop fidgeting. \nPossible side-effects of this medicine include:\n\tNausea\n\tVomiting\n\tTrouble sleeping\n\tHeadache\n\tDizziness\n\tDry mouth\n\tStomach pain\n\tLoss of appetite\n", 60);
			goto meds;
		}
		else
		{
			system("cls");
			emergency(patient_num, threat, "ADHD");
		}
		menu();
	}
	//medication function ends here
};
//Sub class END: ADHD
//source subclasses end


//quiz for illness determining patients illness by asking a set of questions and returning a number representing the illness
int illness_quiz(){
    int ill;
    string ans;
    TypeWriter("\nDo you feel overwhelmingly sad sometimes often not knowing why?\n",60);
    cin>>ans;
    if (ans=="Yes"||ans=="YES"||ans=="yes")
    {
        ill=1;
        return ill;
    }
    else
    {
        TypeWriter("\nDo you have sleeping problems often? (Trouble falling asleep or staying asleep)\n",60);
        cin>>ans;
        if (ans=="Yes"||ans=="YES"||ans=="yes")
        {
            ill=2;
            return ill;
        }
        else
        {
           TypeWriter("\nDo you commonly feel restless, have trouble concentrating or stress out a lot?\n",60);
           cin>>ans;
           if (ans=="Yes"||ans=="YES"||ans=="yes")
           {
               ill=3;
               return ill;
           }
           else
           {
               TypeWriter("\nDo you often have obsessive thoughts or compulsive behaviours that interfere with your daily life?\n",60);
               cin>>ans;
               if (ans=="Yes"||ans=="YES"||ans=="yes")
               {
                   ill=4;
                   return ill;
               }
               else
               {
                   TypeWriter("\nDo you have trouble focusing or concentrating on tasks/being forgetful about completing tasks/easily distracted/having difficulty sitting still?\n",60);
                   cin>>ans;
                   if (ans=="Yes"||ans=="YES"||ans=="yes")
                   {
                       ill=5;
                       return ill;
                   }
                   else
                   {
                       cout<<"\nERROR. We are not yet specialized in finding the illness you have. Sorry for the inconvenience, but maybe you have none!!\n";
                   }   
               }
           }
        }
    }
}

//quiz for threat
int quiz_threat() //a function that will determine how much level of anxiety user still has by taking a short quiz
{
	showLoadingScreen();
	system("cls");
	changeColour(PURPLE);
	TypeWriter(R"(
  ________                    __     ____       __            __  _                ____        _    
 /_  __/ /_  ________  ____ _/ /_   / __ \___  / /____  _____/ /_(_)___  ____     / __ \__  __(_)___
  / / / __ \/ ___/ _ \/ __ `/ __/  / / / / _ \/ __/ _ \/ ___/ __/ / __ \/ __ \   / / / / / / / /_  /
 / / / / / / /  /  __/ /_/ / /_   / /_/ /  __/ /_/  __/ /__/ /_/ / /_/ / / / /  / /_/ / /_/ / / / /_
/_/ /_/ /_/_/   \___/\__,_/\__/  /_____/\___/\__/\___/\___/\__/_/\____/_/ /_/   \___\_\__,_/_/ /___/
                                                                                                    )""\n", 5);
	int threat_level = 0;
	string text;
	int anxiety = 0, ocd = 0, depression = 0, adhd = 0, insomnia = 0;
	//these points will keep adding up and depending upon the score, adding up threat level of user 
	int option; //option value either 1, 2 or 3

	changeColour(BLUE);
	TypeWriter("\n\nAre you thinking about seeking the help of a therapist? If certain issues have been causing problems in your life \nand you aren't sure how to make the necessary changes, therapy can help. With the help \nof a professional, you can get out of an unhealthy cognitive, emotional, and behavioral pattern.\n", 60);
	changeColour(YELLOW);
	TypeWriter("\nFill out the following questionnaire truthfully. The results will only be helpful if you answer in an honest and complete manner.\n\n", 60);
	TypeWriter("1 - Are you feeling very anxious, worried or scared about a lot of things your my life?\n", 60); //threat quiz starts here
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		anxiety += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("2 - Are you finding it hard to keep control over your thoughts and continue worrying?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		anxiety += 1;
		ocd += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("3 - Are you feeling extremely restless, agitated, frantic, or tense?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		anxiety += 1;
		ocd += 1;
		depression += 1;
		insomnia += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("4 - Are you having trouble sleeping or didn't feel well-rested when you last woke up?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		insomnia += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("\nSometimes, people experience a sudden, unexpected wave of intense anxiety or panic, usually lasting not more than 15 minutes.\nIn the past 6 months, did you experience such an attack with any of the following symptoms ? If so, how strong were the symptoms ? \n", 60);
	TypeWriter("5 - Do you have increased heart rate?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		adhd += 1;
		ocd += 1;
		anxiety += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("6 - Do your hands, legs or entire body start shaking, trembling, or fell tingly ?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		ocd += 1;
		anxiety += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("7 - Do you have difficulty breathing or swallowing?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		ocd += 1;
		anxiety += 1;
		depression += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("8 - Do you experience strong fear that causes panic, shortness of breath, chest pains, a pounding heart, sweating, shaking, nausea, dizziness and/or fear of dying?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		anxiety += 1;
		depression += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("9 - Do you have irregular stomach pain and bowel movement?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		ocd += 1;
		anxiety += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("10 - How frequently have you experienced panic attacks in the last 6 months?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		ocd += 1;
		anxiety += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("11 - Do you purposely avoid situations or activities in which you might experience a panic attack?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		ocd += 1;
		anxiety += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("12 - Do you ever engage in repetitive behaviors to manage your worry? (For example, checking that the oven is off, locking doors, washing hands, counting, repeating words?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		ocd += 1;
		anxiety += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("13 - Do you often worry even before bedtime that you won't fall asleep?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		anxiety += 1;
		depression += 1;
		insomnia += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("14 - Do you have trouble focusing, concentrating, or remembering things?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		anxiety += 1;
		depression += 1;
		insomnia += 1;
		ocd += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("15 - Do you fell slowed down compared to your usual pace or have you stopped having fun doing things that you used to enjoy before?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		depression += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("16 - Have you experienced an unusually elevated mood where you were extremely elated, energetic, or irritable or had times when you needed little or no sleep, yet functioned as well or better than usual?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		adhd += 1;
		insomnia += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("17 - Are you feeling extremely sad, empty, hopeless, worthless or guilty?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		depression += 1;
		anxiety += 1;
		ocd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("18 - Are there any noticable changes in your appetite, eating habit or weight?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 1;
		depression += 1;
		anxiety += 1;
		ocd += 1;
		insomnia += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	TypeWriter("19 - How often do you feel positive about your life?\n", 60);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level -= 1;
	}
	else if (option == 2)
	{
		threat_level;
	}
	else if (option == 3)
	{
		threat_level += 1;
		depression += 1;
		anxiety += 1;
		ocd += 1;
		insomnia += 1;
		adhd += 1;
	}

	TypeWriter("20 - Have you been having sucidal thoughts recently?\n", 60);
	changeColour(RED);
	TypeWriter("NOTE: CHOOSE THE OPTION CAREFULLY\n", 60);
	changeColour(YELLOW);
	cout << "\t1. " << "Very Often" << endl << "\t2. " << "Sometimes" << endl << "\t3. " << "Never" << endl;
	cin >> option;
	if (option == 1)
	{
		threat_level += 3;
		anxiety += 1;
		depression += 1;
		insomnia += 1;
		ocd += 1;
		adhd += 1;
	}
	else if (option == 2)
	{
		threat_level += 1;
	}
	else if (option == 3)
	{
		threat_level -= 1;
	}

	cout << "Your Threat level is: " << threat_level << endl;
	//results for threat levelscout << "Your Threat level is: " << threat_level << endl;
	//results for threat levels

	if (threat_level <= 10)//sum less that 10
	{
		cout << "Your symptoms are minor at this time. You could still benefit from talking to a professional. Take a day off and try to get rid of the excessive stress from the past days. \n";
	}
	else if (threat_level >= 10 || threat_level <= 17) //if sum is greater than or equal to 10 or less than 19 
	{
		cout << "Your symptoms are high at this time. You could still benefit from talking to a professional and seek medical advice as soon as possible for improvement of your mental health as well as physical health.\n  \n";
	}
	else if (threat_level >= 18) //if sum is greater than or equal to 20
	{
		cout << "Your mental health seems very unstable at the moment. It is advised that you consult a therapist and get treated immediately. An ambulance will be called for you soon. \n";
	}

	TypeWriter("\nWould you like to get detailed results for your illness threat level?\n", 60);
	cin >> text;
	if (text == "YES" || text == "Yes" || text == "yes")
	{
		cout << "\n\nYour Depression Threat level is: " << depression << endl << endl;
		//results for depression threat levels
		if (depression >= 15)//gives depression reports
		{
			TypeWriter("\nYou show symptoms of the depression with a high risk level. While they have not reached the level of full diagnosis, \nseeking the advice of a therapist is recommended, as the symptoms may become overwhelming, more frequent, and more serious.", 60);
		}
		else if (depression >= 7 || depression <= 14)
		{
			TypeWriter("\nYou display mild symptoms of depression. This issue does not seem to be serious at this time, but your symptoms - as indicated in the test - should be monitored. \nIf they get any worse or persist for a prolonged period of time (weeks or months), you should consider consulting a health professional.\n", 60);
		}
		else  if (depression <= 6)
		{
			TypeWriter("\nYou do not appear to have any symptoms of depression. This does not exclude you from OCD or anxiety, but you show no signs of the depression that this disorder entails.\n", 60);
		}

		cout << "\n\nYour Anxiety Threat level is: " << anxiety << endl << endl;
		//results for anxiety threat levels
		if (anxiety >= 10)//anxiety test reports 
		{
			TypeWriter("\nYou show symptoms of the anxiety with a high risk level. While they have not reached the level of full diagnosis, \nseeking the advice of a therapist is recommended, as the symptoms may become overwhelming, more frequent, and more serious.", 60);
		}
		else if (anxiety >= 5 || anxiety <= 9)
		{
			TypeWriter("\nYou display mild symptoms of anxiety. This issue does not seem to be serious at this time, but your symptoms - as indicated in the test - should be monitored. \nIf they get any worse or persist for a prolonged period of time (weeks or months), you should consider consulting a health professional.\n", 60);
		}
		else  if (anxiety <= 4)
		{
			TypeWriter("\nYou do not appear to have any symptoms of anxiety. This does not exclude you from OCD or depression, but you show no signs of the anxiety that this disorder entails.\n", 60);
		}

		cout << "\n\nYour OCD Threat level is: " << ocd << endl << endl;
		//results for ocd threat levels
		if (ocd >= 7)//ocd test reports 
		{
			TypeWriter("\nYou show symptoms of the OCD with a high risk level. While they have not reached the level of full diagnosis, \nseeking the advice of a therapist is recommended, as the symptoms may become overwhelming, more frequent, and more serious.", 60);
		}
		else if (ocd >= 3 || ocd <= 6)
		{
			TypeWriter("\nYou display mild symptoms of OCD. This issue does not seem to be serious at this time, but your symptoms - as indicated in the test - should be monitored. \nIf they get any worse or persist for a prolonged period of time (weeks or months), you should consider consulting a health professional.\n", 60);
		}
		else  if (ocd <= 2)
		{
			TypeWriter("\nYou do not appear to have any symptoms of OCD. This does not exclude you from depression or anxiety, but you show no signs of the OCD that this disorder entails.\n", 60);
		}

		cout << "\n\nYour ADHD Threat level is: " << adhd << endl << endl;
		//results for adhd threat levels
		if (adhd >= 7)//adhd test reports 
		{
			TypeWriter("\nYou show symptoms of the ADHD with a high risk level. While they have not reached the level of full diagnosis, \nseeking the advice of a therapist is recommended, as the symptoms may become overwhelming, more frequent, and more serious.", 60);
		}
		else if (adhd >= 3 || adhd <= 6)
		{
			TypeWriter("\nYou display mild symptoms of ADHD. This issue does not seem to be serious at this time, but your symptoms - as indicated in the test - should be monitored. \nIf they get any worse or persist for a prolonged period of time (weeks or months), you should consider consulting a health professional.\n", 60);
		}
		else  if (adhd <= 2)
		{
			TypeWriter("\nYou do not appear to have any symptoms of ADHD. This does not exclude you from depression or OCD, but you show no signs of the ADHD that this disorder entails.\n", 60);
		}

		cout << "\n\nYour Insomnia Threat level is: " << insomnia << endl << endl;
		//results for insomnia threat levels
		if (insomnia >= 5)//insomnia test reports 
		{
			TypeWriter("\nYou show symptoms of the insomnia with a high risk level. While they have not reached the level of full diagnosis, \nseeking the advice of a therapist is recommended, as the symptoms may become overwhelming, more frequent, and more serious.", 60);
		}
		else if (insomnia >= 3 || insomnia <= 4)
		{
			TypeWriter("\nYou display mild symptoms of insomnia. This issue does not seem to be serious at this time, but your symptoms - as indicated in the test - should be monitored. \nIf they get any worse or persist for a prolonged period of time (weeks or months), you should consider consulting a health professional.\n", 60);
		}
		else  if (insomnia <= 2)
		{
			TypeWriter("\nYou do not appear to have any symptoms of insomnia. This does not exclude you from depression or anxiety, but you show no signs of the insomnia that this disorder entails.\n", 60);
		}
	}
	return threat_level;
}
//threat quiz ends here

//Main function
void Main(){
    int ill;
    int patients;
    int choice;
    string ans;
    mental_illness *patient[100];//creates an array of objects to tend to multiple patients
    changeColour(GREEN);
                TypeWriter(R"(             
      _____      _  __   _    _      _         _____                                     
     / ____|    | |/ _| | |  | |    | |       |  __ \                                    
    | (___   ___| | |_  | |__| | ___| |_ __   | |__) | __ ___   __ _ _ __ __ _ _ __ ___  
     \___ \ / _ \ |  _| |  __  |/ _ \ | '_ \  |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \ 
     ____) |  __/ | |   | |  | |  __/ | |_) | | |   | | | (_) | (_| | | | (_| | | | | | |
    |_____/ \___|_|_|   |_|  |_|\___|_| .__/  |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|
                                      | |                       __/ |                    
                                      |_|                      |___/    )""\n" ,5);
    changeColour(BLUE);
    TypeWriter("\nWelcome to the Self-help program! We aim to determine your illness and aid you in health. How many patients do you wish to see:\n",60);
    cin>>patients;//enter number of patients
    for (int i = 0; i < patients; i++)// for each patient
    {
        TypeWriter("\nWelcome! Please choose an option that best fits you to continue:\n",60);
        TypeWriter("\n\t1. I know my mental illness.\n\t2. I dont know my mental illness",60);//two scenarios
        invalid:
        cin>>choice;
        switch (choice)
        {
        case 1: 
            changeColour(YELLOW);
            LineBreak('-', 90);
            changeColour(PURPLE);
            cout << "\n\t[>>] Depression \n\t[>>] Insomnia \n\t[>>] Anxiety \n\t[>>] ADHD \n\t[>>] OCD\n";
            changeColour(WHITE);
            TypeWriter("\nEnter Illness: ",60);
            cin>>ans;//take input if they know it
            if (ans=="Depression"||ans=="depression")//create objects according to inheritance
            {
                cout<<"\nWhat kind? 1. Major Depressive disorder 2. Persistent Depressive Disorder\n";
                cin>>choice;
                if (choice==1)
                {
                    patient[i] = new Type1_depression;//create an object of the class of specified illness on ith position
                    patient[i]->User_data(i);//get input
                    //set values
                    patient[i]->set_patient_num(i);
                    patient[i]->set_illness("Depression");
                    patient[i]->set_threat(quiz_threat());//call threat quiz and pass value to set
                    patient[i]->Menu();//call menu
                }
                else
                {
                    patient[i] = new Type2_depression;
                    patient[i]->set_patient_num(i);
                    patient[i]->set_illness("Depression");
                    patient[i]->set_threat(quiz_threat());
                    patient[i]->User_data(i);
                    patient[i]->Menu();
                }
            } 
            else if (ans=="Insomnia"||ans=="insomnia")
            {
                patient[i] = new Insomnia;
                patient[i]->User_data(i);
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("Insomnia");
                patient[i]->set_threat(quiz_threat());
                    system("cls");
                    showLoadingScreen();
                    system("cls");
                    changeColour(DEFAULTCOLOUR);
                    quicken();
                    cout << "Welcome! , use arrow keys to highlighted the given options and press 'Enter' key to select.\n";//graphical perk added
                    changeColour(YELLOW);
                    LineBreak('=', 95);
                    patient[i]->menu();
            }
            else if(ans=="Anxiety"||ans=="anxiety"){
                patient[i]=new Anxiety;
                patient[i]->User_data(i);
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("Anxiety");
                patient[i]->set_threat(quiz_threat());
                system("cls");
                showLoadingScreen();
                system("cls");
                changeColour(DEFAULTCOLOUR);
                quicken();
                cout << "Welcome! It is recommended to open the program in fullscreen mode. \nUse arrow keys to highlighted the given options and press 'Enter' key to select.\n";
                changeColour(YELLOW);
                LineBreak('=', 95);
                patient[i]->menu();
            }
            else if(ans=="ADHD"||ans=="adhd"){
                patient[i]=new ADHD;
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("ADHD");
                patient[i]->set_threat(quiz_threat());
                patient[i]->User_data(i);
                patient[i]->menu();
                system("cls");
                showLoadingScreen();
                system("cls");
            }
            else if(ans=="OCD"||ans=="ocd"){
                patient[i]=new OCD;
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("OCD");
                patient[i]->set_threat(quiz_threat());
                patient[i]->User_data(i);
                system("cls");
                showLoadingScreen();
                system("cls");
                changeColour(DEFAULTCOLOUR);
                quicken();
                cout << "Welcome! It is recommended to open the program in fullscreen mode. \nUse arrow keys to highlighted the given options and press 'Enter' key to select.\n";
                changeColour(YELLOW);
                LineBreak('=', 95);
                patient[i]->menu();  
            }
            else//exception handler
            {
                cout<<"\nSorry, we are un-speacalized in treating this kind of illness.\n";
            }
            
            break;
        case 2://if user doesnt know their illness
            ill=illness_quiz();//call illness determinor quiz and assign values for each illness
            if (ill==1)//if illness==depression create a new object in ith position of depression
            {
                TypeWriter("You are determined to have Depression, but there are 2 kinds. Please the number for which one you have; 1. Major Depressive disorder 2. Persistent Depressive Disorder: ",60);
                cin>>choice;
                if (choice==1)
                {
                    patient[i] = new Type1_depression;
                    patient[i]->User_data(i);
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("Depression");
                patient[i]->set_threat(quiz_threat());
                    patient[i]->Menu();
                }
                else
                {
                    patient[i] = new Type2_depression;
                    patient[i]->User_data(i);
                    patient[i]->set_patient_num(i);
                patient[i]->set_illness("Depression");
                patient[i]->set_threat(quiz_threat());
                    patient[i]->Menu();
                }
            }
            else if (ill==2)//if illness==insomnia
            {
                patient[i] = new Insomnia;
                patient[i]->User_data(i);
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("Insomnia");
                patient[i]->set_threat(quiz_threat());
                    system("cls");
                    showLoadingScreen();
                    system("cls");
                    changeColour(DEFAULTCOLOUR);
                    quicken();
                    cout << "Welcome! , use arrow keys to highlighted the given options and press 'Enter' key to select.\n"; 
                    changeColour(YELLOW);
                    LineBreak('=', 95);
                    patient[i]->menu();
            }
            else if(ill==3){//if illness==anxiety
                patient[i]=new Anxiety;
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("Anxiety");
                patient[i]->set_threat(quiz_threat());
                patient[i]->User_data(i);
                system("cls");
                showLoadingScreen();
                system("cls");
                changeColour(DEFAULTCOLOUR);
                quicken();
                cout << "Welcome! It is recommended to open the program in fullscreen mode. \nUse arrow keys to highlighted the given options and press 'Enter' key to select.\n";
                changeColour(YELLOW);
                LineBreak('=', 95);
                patient[i]->menu();  
            }
            else if(ill==4)//if illness==OCD
            {
                patient[i]=new OCD;
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("OCD");
                patient[i]->set_threat(quiz_threat());
                patient[i]->User_data(i);
                system("cls");
                showLoadingScreen();
                system("cls");
                changeColour(DEFAULTCOLOUR);
                quicken();
                cout << "Welcome! It is recommended to open the program in fullscreen mode. \nUse arrow keys to highlighted the given options and press 'Enter' key to select.\n";
                changeColour(YELLOW);
                LineBreak('=', 95);
                patient[i]->menu();  
            }
            else if(ill==5)//if illness= ADHD
            {
                patient[i]=new ADHD;
                patient[i]->set_patient_num(i);
                patient[i]->set_illness("ADHD");
                patient[i]->set_threat(quiz_threat());
                patient[i]->User_data(i);
                patient[i]->menu();
                system("cls");
                showLoadingScreen();
                system("cls");
            }
            break;
        default:
        cout<<"INVALID ENTRY> PLEASE TRY AGAIN: ";
        goto invalid;
            break;
        }
    }
}

// driver function
int main()
{
    Main();

    return 0;
}