Tempreture Data Input
på rad 15
start med deklarering av listan (DataEntries) som datan ska in i.


på rad 16-17
Efter detta så deklarerar jag classerna så jag kan använda dem i resten av programet och deklarerar bool run för att börja while loopen.
på rad 18 
lässer in specific txt fil  med  function ReadFile();

{
 ifstream TempretureFile;
 //går igenom värdena som var innan och skickar in dem i listan
 TempretureFile.open("DataVals.txt", ios::in);
 if (TempretureFile.is_open())
 {
     int times = 0;
     std::vector<Measurement> Values(3);
     string line;
     //här går den igenom alla lines av txt filen samt lägger dem in i vector som sätts in i listan
     while (getline(TempretureFile, line))
     {
         char str[256];
         strcpy_s(str, line.c_str());
         const char* del = ",";
         Measurement new_measurement;
         char* next_token = nullptr;
         char* FileSegment = strtok_s(str, del, &next_token);
         int FileIteration = 0;
         while (FileSegment != nullptr) 
         {
             if (FileIteration == 0)
             {
                 new_measurement.TimeStamp = FileSegment;
             }
             else if (FileIteration == 1)
             {
                 new_measurement.TempretureNumber = FileSegment;
             }
             else if (FileIteration == 2)
             {
                 new_measurement.TepretureInput = stod(FileSegment);
             }
             
             FileSegment = strtok_s(nullptr, del, &next_token);
             FileIteration++;
         }
         MeasurmentList.push_back(new_measurement);
     }
 }
 TempretureFile.close();
}
på rad 21-30
I main while loopen har jag en "system("CLS");" i början för att cleana up från tidigare inputs samt menyer. efter det så har jag min "main.PrintMenu();" funtion som är bara massa couts som skriver menyn. deklarerar sedan en variabel för meny valet Choise som jag tar igenom en function jag skapa "main.NumberChoice(MenyChoice);" för att hantera ifal att användaren skrev en bokstav istället för en sifra eller fel option gjorde så jag inte behövde skriva om samma kod om och om igen.
NumberChoice();
{
 static int NumberChoice(std::string StringInput)
 {
    // jag gör alla cout innan denna function till strings som jag kan lägga in här för en dynamisk så jag inte behöver ändra så mycket i koden när jag lägger till den här functionen
    std::cout << StringInput << std::endl;

    int Choice;

    //failsafe loop för val
    while (!(std::cin >> Choice))// detta är en while loop "!" gör att den nomalt sätt är false hela tiden om du har correct input de vill säga nummer inte bokstever om du srkiver en bokstav så kommer den bli                                      // värdet bli false men "!" gör om den till true och den kommer gå om och om igen till du skriver ett svar som gör loopen false
    {

        std::cout << "Error you have inputed a invalid value please input a number:  " << std::endl;
        std::cin.clear();// detta clearar vad du skrev om du skrev en fel input
        std::streamsize InputBufferLimit = 10000;
        std::cin.ignore(InputBufferLimit, '\n');
        std::cout << StringInput << std::endl; // lägger till här så när man har fel så frågar den samma fråga som den började med för att få rätt svar

    }

    // om man skrev allt correct å ger 
    return Choice;
 }
}
på rad 31-32
är en switch med 6 cases och en default om man skriver ett nummer som inte är en av valen.




på rad 33-52 
är case 1 som är valet för att lägga in value manuelt
innehåller "system("CLS");" som jag har för samma anledning som jag skrev tidigare. har även "main.NumberChoice();" för hur många värden man vill lägga in som jag lägger in i en int times variabel som jag deklarerar på samma rad som bästemer för for loopen när den ska sluta
{
 system("CLS");
 
 std::string TepretureInputs = "How many values do you want to add";
 //här inisierar jag hur många värden jag vill ha
 int NumberOfInputs = DataInput.NumberChoice(TepretureInputs);
 for (int i = 0; i < NumberOfInputs; i++)
 {
     // Vill ta in en termperatur: InputVal
     // Vill ta fram timestamp för NU
     double TempretureInput = 0;
     std::cin >> TempretureInput;//här kan man manuelt skriva vilket värde man vill ha
     // Skapa ny t.ex. Meaurement-instans
     // och lägg till i vector
     //DataEntries.push_back(Measurement(inputVal, timestamp));
     DataInput.TempretureListInput(i, DataEntries, TempretureInput);
 }
}
{
void TempretureListInput(int i, std::vector<Measurement>& MeasurmentList, double InputTempreture)
{
    ofstream TempretureData;
    
    std::cout << "[" << i + 1 << "]" << "Value: ";
    //här är för att lägga till tiden
    time_t TimeStamp;
    time(&TimeStamp);
    struct tm timeInfo;
    localtime_s(&timeInfo, &TimeStamp);
    char temp[26];
    asctime_s(temp, sizeof(temp), &timeInfo);
    temp[strlen(temp) - 1] = '\0'; // tar bort newline
    
    //new_measurement.TimeStamp = temp;
    //detta är för att ge nummeret på vilken värde det är
    std::string convert = std::to_string((size(MeasurmentList) + 1));
    std::string dataLabel = convert + "#";
    std::cout << dataLabel << std::endl;
    
    Measurement new_measurement{dataLabel, temp, InputTempreture };
    //här öppnar jag upp en ny txt.fil som jag lägger in värden i
    TempretureData.open("DataVals.txt", ios::app);
    if (TempretureData.is_open())
    {
        //här läggs det in i txt.filen
        TempretureData << new_measurement.TimeStamp << ",";
        TempretureData << new_measurement.TempretureNumber << ",";
        TempretureData << new_measurement.TepretureInput << endl;
        TempretureData.close();
    }
    MeasurmentList.push_back(new_measurement);
}
}
på rad 53-84
är case 2 som är utskrivning av värderna
Börjar med en system("CLS"); och deklarering av bool för en while loop.
 {
    while (Print == true)
    {

        std::cout << "You have [" << size(DataEntries) << "]" << std::endl; // skriver hur många vectorer(värden) som finns i din lista eller "i systemet"
        std::cout << "Do you want to list them [Y/N] : " << std::endl; // jag ger dig ett val om du vill printa ut alla values eller om du inte vill göra det (Y för ja / N för nej)
        char Des;
        std::cin >> Des;

        //använder toupper så man kan skriva bådde stor eller liten bokstav
        if ((char)toupper(Des) == 'Y')
        {

            //detta går igenom alla vectorer och skriver ut dem
            main.PrintVectorList(DataEntries);// function för att printa utt all values från listan 

            Print = false;

        }

        else if ((char)toupper(Des) == 'N')// detta tar tillbacka dig till menyn
        {


            Print = false;


        }

        else// detta ifal du skrev en bokstav som inte var en option de vill säga  inte Y/N
        {


            std::cout << "Wrong input" << std::endl;


        }

        break;

    }

}

//ENTER(); är en funtion som bara gör att du måste kicka enter för att continue

break;
}
{
void PrintMeasurementList(const std::vector<Measurement>& MeasurmentList)
{
    for (int i = 0; i < size(MeasurmentList); i++)
    {
        std::cout << "--------------------\n" << std::endl;
        std::cout << MeasurmentList[i].TimeStamp << "\n" << std::endl;
        std::cout << MeasurmentList[i].TempretureNumber << std::endl;
        std::cout << MeasurmentList[i].TepretureInput << " C" << std::endl;
        std::cout << "\n--------------------" << std::endl;
    }
}
}
{
void ENTER()
{

    std::cout << "Klick \"ENTER\" too continue" << std::endl;

    std::string str;

    std::getline(std::cin, str);

    std::streamsize InputBufferLimit = 10000;

    std::cin.ignore(InputBufferLimit, '\n');
}
}
på rad 85-162
case 3 är för statistiken av all temperatur data 
börjar med att fråga om man vill lägga till avancerad data som movingavarage och gränsvärden du skriver antingen Y eller N. 
annars så går den igenom och tittar hur många värden man har om man har vectorn har mindre en 1 värde så kommer den säga att man inte har några värden och ta tillbacka en till menyn, om man har ett värde så säger den att du har ett värde och säger vad det värdet är och om du har mer en ett värde så går den igenom allt.
som summan av alla som den går igenom i SummOfVector(); functionen
{
static double SummOfVector(const std::vector<Measurement>& MeasurmentList)
{
    double SumVal = 0;
    for (int i = 0; i < size(MeasurmentList); i++)// går igenom hela vectorn
    {
        
        SumVal = SumVal + MeasurmentList[i].TepretureInput;//plussar ihop alla TepretureInput värden in i variablen SumVal
    }
    return SumVal;
}
}
värdet jag får från SummOfVector(); delar jag med size(DataEntries); för att få ut avarage.

sen deklarerar jag strings för min och max värdet och doublen för min och max värdet efter det går vectorn igenom och kollar på min och max värdet med PrintListMax(); och PrintListMin();
{
static std::tuple<std::string, std::string, double>  PrintListMax(const std::vector<Measurement>& MeasurmentList)
{
    //minimum valuen så att koden har en refrence att comparea mot
    double MaxVal = std::numeric_limits<double>::min();
    //detta frå fram max value
    std::string TimeMax;
    std::string IdMax;
    for (int i = 0; i < size(MeasurmentList); i++)//checkar genom listan alla vectorer
    {
        double Temp = MeasurmentList[i].TepretureInput;
        //gör [1] för att det är på den indexen som data valuen är på
        if (Temp > MaxVal)
        {
            TimeMax = MeasurmentList[i].TimeStamp;
            IdMax = MeasurmentList[i].TempretureNumber;
            MaxVal = Temp;
        }
    }
    return std::make_tuple(TimeMax, IdMax, MaxVal);
}
}
{
static std::tuple<std::string, std::string, double> PrintListMin(const std::vector<Measurement>& MeasurmentList)
{
    //denna variabel tar fram max value för att comparea cilken som är minst
    double MinVal = std::numeric_limits<double>::max();
    // detta får fram minsta value
    std::string TimeMin;
    std::string IdMin;
    for (int i = 0; i < size(MeasurmentList); i++)
    {
        double temp = MeasurmentList[i].TepretureInput;
        if (temp < MinVal)
        {
            TimeMin = MeasurmentList[i].TimeStamp;
            IdMin = MeasurmentList[i].TempretureNumber;
            MinVal = temp;
        }
    }
    return std::make_tuple(TimeMin, IdMin, MinVal);
}
}

på rad 163-180
case 4 är för att simulera random temperatur värden
på rad 181-194
case 5 är visualisering av datan den printar "*" för temperatur värdet
på rad 195-197
case 6 den här gör att run boolen för meny loopen för att sluta programet
på rad 198-201
default ifal man skriver något nummer som inte är del av menyn så skriver den bara ut att man ska skriva en ny input










