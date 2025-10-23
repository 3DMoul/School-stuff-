Tempreture Data Input
på rad 17
start med deklarering av listan (DataEntries) som datan ska in i.

på rad 18-48
sen lägger jag in selectad txt file jag använder en while loppe för att gå igenom och ge mig alla rader som jag lägger in i en vector som jag lägger in i listan. Pågrund av hur jag har laggt in text i filen så måste jag ha ett sätt att lägga in rader på index "0,1,2" sen reseta så jag deklarerar en int times som ökar värde varje runda igenom while loppen detta times värde ger mig min index så att värderna är i rätt index när jag lägger in dem i listan och när times värde är "3" så har jag en if statment som lägger in linen i vectorn är att så lägge (times < 3)så ska den göra det if statment som lägger till vectorn med värden in i listan och sätter times värdet till "0" igen.

på rad 51-55
Efter detta så deklarerar jag classen och structen så jag kan använda dem i resten av programet och deklarerar bool run för att börja while loopen.

på rad 67-74
I main while loopen har jag en "system("CLS");" i början för att cleana up från tidigare inputs samt menyer. efter det så har jag min "main.PrintMenu();" funtion som är bara massa couts som skriver menyn. deklarerar sedan en variabel för meny valet Choise som jag tar igenom en function jag skapa "main.NumberChoice(MenyChoice);" för att hantera ifal att användaren skrev en bokstav istället för en sifra eller fel option gjorde så jag inte behövde skriva om samma kod om och om igen.
NumberChoice();

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
på rad 76-342
är en switch med 6 cases och en default om man skriver ett nummer som inte är en av valen.




på rad 78-98 
är case 1 som är valet för att lägga in value manuelt
innehåller "system("CLS");" som jag har för samma anledning som jag skrev tidigare. har även "main.NumberChoice();" för hur många värden man vill lägga in som jag lägger in i en int times variabel som jag deklarerar på samma rad som bästemer för for loopen när den ska sluta
for (int i = 0; i < Times; i++)// så lägge i är mindre en times så kommer loopen itireras i ökar med "+1" varje loop
{

    double InputVal = 0;
    std::cin >> InputVal;//här kan man manuelt skriva vilket värde man vill ha
    DataEntries.push_back(DataIn.DataListInput(i, DataEntries, InputVal));// här lägger den till en vector som har alla värden för detta data set vilken tid den skapades vilket "#" den är i listan och värden
    //som du mannuelt skrev in till listan. Man får alla dessa värden genom  "DataIn.DataListInput(i, DataEntries, InputVal)" functionen som jag skapa.
    

}

static std::vector<std::string> DataListInput(int i, std::list<std::vector<std::string>>& InputList, double InputValue)
{

    //vector för värdet med storlek (3) så jag kan ha tid när den skapades nummer# vilken årdning den skapades och till sist valuen av datan
    std::vector<std::string> Values(3);

    std::cout << "[" << i + 1 << "]" << "Value: ";

    //här är för att lägga till tiden
    //Time_t  is used to store a timestamp value 
    time_t TimeStamp;
    //Time() gives you current time and date 
    time(&TimeStamp);
    char *temp;
    temp = asctime(localtime(&TimeStamp));
    temp[strlen(temp) - 1] = '\0';// detta gör att man inte får den newline av time_t
    Values[0] = temp;
    

    //detta är för att ge nummeret på vilken värde det är
    std::string convert = std::to_string((size(InputList) + 1));
    std::string dataLabel = convert + "#";
    std::cout << dataLabel << std::endl;
    Values[1] = dataLabel;


    std::string TempString = std::to_string(InputValue);
    Values[2] = TempString;

    //här öppnar jag upp en ny txt.fil som jag lägger in värden i
    TxTData.open("DataVals.txt", ios::app);
    if (TxTData.is_open())
    {
        
        //här läggs det in i txt.filen
        TxTData << Values[0] << endl;
        TxTData << Values[1] << endl;
        TxTData << Values[2] << endl;
        TxTData.close();
    }

    // ger tillbacka vectorn som läggs in i listan
    return Values;

}

på rad 101-154
är case 2 som är utskrivning av värderna
Börjar med en system("CLS"); och deklarering av bool för en while loop.
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
void PrintVectorList(const std::list<std::vector<std::string>>& InputList)
{
    for (const auto& vec : InputList)
    {
        std::cout << "--------------------\n" << std::endl;
        std::cout << vec[0] << "\n" << std::endl;
        std::cout << vec[1] << std::endl;
        std::cout << vec[2] << " C" << std::endl;
        std::cout << "\n--------------------" << std::endl;
    }
}
void ENTER()
{

    std::cout << "Klick \"ENTER\" too continue" << std::endl;

    std::string str;

    std::getline(std::cin, str);

    std::streamsize InputBufferLimit = 10000;

    std::cin.ignore(InputBufferLimit, '\n');
}









