Tempreture Data Input

på rad 15
Start med deklarering av listan (DataEntries) som datan ska in i.

på rad 16–18
Efter detta så deklarerar jag klasserna så jag kan använda dem i resten av programmet och deklarerar bool run för att börja while-loopen.

på rad 18
Läser in specifik txt-fil med funktionen ReadFile();

{
    
	ifstream TempretureFile;
    
	// går igenom värdena som var innan och skickar in dem i listan
    
	TempretureFile.open("DataVals.txt", ios::in);
   
	if (TempretureFile.is_open())
    {
      
		int times = 0;
       
		std::vector<Measurement> Values(3);
        
		string line;
        
		// här går den igenom alla lines av txt-filen samt lägger dem in i vector som sätts in i listan
      
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


på rad 21–30
I main while-loopen har jag en system("CLS"); i början för att cleana upp från tidigare inputs samt menyer.
Efter det så har jag min main.PrintMenu(); funktion som bara är massa cout som skriver menyn.
Deklarerar sedan en variabel för menyvalet Choice som jag tar igenom en funktion jag skapade:
main.NumberChoice(MenyChoice);
för att hantera ifall användaren skrev en bokstav istället för en siffra eller fel option.

NumberChoice();
{
    static int NumberChoice(std::string StringInput)
    {
        // jag gör alla cout innan denna function till strings som jag kan lägga in här för en dynamisk
        std::cout << StringInput << std::endl;

        int Choice;

        // failsafe loop för val
        while (!(std::cin >> Choice))
        {
            std::cout << "Error you have inputed a invalid value please input a number:  " << std::endl;
            std::cin.clear(); // detta clearar vad du skrev om du skrev en fel input
            std::streamsize InputBufferLimit = 10000;
            std::cin.ignore(InputBufferLimit, '\n');
            std::cout << StringInput << std::endl; // frågar igen samma fråga
        }

        // om man skrev allt korrekt
        return Choice;
    }
}


på rad 31–32
Är en switch med 6 cases och en default om man skriver ett nummer som inte är en av valen.

på rad 33–52
Case 1 – valet för att lägga in value manuellt.

{
    system("CLS");
 
    std::string TepretureInputs = "How many values do you want to add";
    int NumberOfInputs = DataInput.NumberChoice(TepretureInputs);

    for (int i = 0; i < NumberOfInputs; i++)
    {
        double TempretureInput = 0;
        std::cin >> TempretureInput;

        DataInput.TempretureListInput(i, DataEntries, TempretureInput);
    }
}

{
    void TempretureListInput(int i, std::vector<Measurement>& MeasurmentList, double InputTempreture)
    {
        ofstream TempretureData;
    
        std::cout << "[" << i + 1 << "]" << "Value: ";

        // lägger till tiden
        time_t TimeStamp;
        time(&TimeStamp);
        struct tm timeInfo;
        localtime_s(&timeInfo, &TimeStamp);
        char temp[26];
        asctime_s(temp, sizeof(temp), &timeInfo);
        temp[strlen(temp) - 1] = '\0'; // tar bort newline
    
        std::string convert = std::to_string((size(MeasurmentList) + 1));
        std::string dataLabel = convert + "#";
        std::cout << dataLabel << std::endl;
    
        Measurement new_measurement{dataLabel, temp, InputTempreture };
		//lägger in temperatur datan in i en text fil
        TempretureData.open("DataVals.txt", ios::app);
        if (TempretureData.is_open())
        {
            TempretureData << new_measurement.TimeStamp << ",";
            TempretureData << new_measurement.TempretureNumber << ",";
            TempretureData << new_measurement.TepretureInput << endl;
            TempretureData.close();
        }
        MeasurmentList.push_back(new_measurement);
    }
}


på rad 53–84
Case 2 – utskrivning av värdena.

{
    while (Print == true)
    {
        std::cout << "You have [" << size(DataEntries) << "]" << std::endl;
        std::cout << "Do you want to list them [Y/N] : " << std::endl;
        char Des;
        std::cin >> Des;

        if ((char)toupper(Des) == 'Y')
        {
            main.PrintVectorList(DataEntries);
            Print = false;
        }
        else if ((char)toupper(Des) == 'N')
        {
            Print = false;
        }
        else
        {
            std::cout << "Wrong input" << std::endl;
        }
        break;
    }
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


på rad 85–162
Case 3 – statistik av all temperaturdata.

{
    static double SummOfVector(const std::vector<Measurement>& MeasurmentList)
    {
        double SumVal = 0;
        for (int i = 0; i < size(MeasurmentList); i++)
        {
            SumVal = SumVal + MeasurmentList[i].TepretureInput;//plussar ihop all TepretureInput in i SumVal
        }
        return SumVal;
    }
}
PrintListMax(); PrintListMin(); hittar max och min values av vectoren
{
    static std::tuple<std::string, std::string, double> PrintListMax(const std::vector<Measurement>& MeasurmentList)
    {
        double MaxVal = std::numeric_limits<double>::min();
        std::string TimeMax;
        std::string IdMax;

        for (int i = 0; i < size(MeasurmentList); i++)
        {
            double Temp = MeasurmentList[i].TepretureInput;
            if (Temp > MaxVal)
            {
                TimeMax = MeasurmentList[i].TimeStamp;
                IdMax = MeasurmentList[i].TempretureNumber;
                MaxVal = Temp;
            }
        }
        return std::make_tuple(TimeMax, IdMax, MaxVal);
		//använder tuple så jag kan få ut all tre värdena med en output så jag inte behöver använda en for loop efter functionen för att få TimeStamp och Tempreture number
    }
}

{
    static std::tuple<std::string, std::string, double> PrintListMin(const std::vector<Measurement>& MeasurmentList)
    {
        double MinVal = std::numeric_limits<double>::max();
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
		//använder tuple så jag kan få ut all tre värdena med en output så jag inte behöver använda en for loop efter functionen för att få TimeStamp och Tempreture number
    }
}
sen går den igenom Variance();
{
	static double Variance(const std::vector<Measurement>& MeasurmentList)
	{
	    //vector för att hålla värderna för varians
	    std::vector<double> StandardDeviation = {};
	    double StandAvg = SummOfVector(MeasurmentList);
	    StandAvg = StandAvg / size(MeasurmentList);
	    //detta subtraherar alla värderna med medelvärdet
	    for (int i = 0; i < size(MeasurmentList); i++)
	    {
	        double Temp = MeasurmentList[i].TepretureInput;
	        double TempVar = Temp - StandAvg;
	        StandardDeviation.push_back(TempVar);
	    }
	    //detta kvadrerar alla dem subtraherade nummrena
	    for (int i = 0; i < size(StandardDeviation); i++)
	    {
	        double TempVar = pow(StandardDeviation[i], 2);
	        StandardDeviation[i] = TempVar;
	    }
	    // deklarering a kvadrerade tal
	    double Squere = 0;
	    //loop för att addera ihop all Kvad tal
	    for (double i : StandardDeviation)
	    {
	        Squere = Squere + i;
	    }
	    return Squere;
	}
}
efter detta så tittar den om du valde avancerade calculering moving avarage och gränsvärden
{
	static std::tuple<int, int> ValueLimit(const std::vector<Measurement>& MeasurmentList, double LV)
	{
	    int TimesOver = 0;
	    int TimesUnder = 0;
	    // denna for loop checkar alla gånger datan är under eller över gränsvärdet man la till
	    for (int i = 0; i < size(MeasurmentList); i++)
	    {
	        double temp = MeasurmentList[i].TepretureInput;
	        if (temp < LV)
	        {
	            TimesUnder++;
	        }
	        else if (temp > LV)
	        {
	            TimesOver++;
	        }
	    }
	    return std::make_tuple(TimesOver, TimesUnder);
	}
}

{
	static double MovingAvarage(double EndBoundry, double BeginBoundry, std::vector<Measurement>& MeasurmentList)
	{
	    double MovingAvarageTemporary = 0;
	    double MovingAvgSizeTemporary = 0;
	    while (EndBoundry < BeginBoundry)
	    {
	        std::cin.clear();
	        std::streamsize InputBufferLimit = 10000;
	        std::cin.ignore(InputBufferLimit, '\n');
	        std::cout << "EndBoundry has to be after BeginBoundry. " << std::endl;
	        std::cout << "Enter another value: ";
	        std::cin >> EndBoundry;
	    }
	    // detta går igenom från där du ville starta till där du villa sluta
	    for (int i = 0; i < size(MeasurmentList); i++)
	    {
	        int temp = MeasurmentList[i].TempretureNumber[0];
	        if (temp >= BeginBoundry)
	        {
	            MovingAvarageTemporary += MeasurmentList[i].TepretureInput;
	            MovingAvgSizeTemporary++;
	        }
	        else if (temp == EndBoundry)
	        {
	            break;
	        }
	    }
	    return MovingAvarageTemporary / MovingAvgSizeTemporary;
	}
}

på rad 163–180
Case 4 – för att simulera random temperaturvärden.
här frågar den hur många tal du vill simulera och sen matar den in random doubles in i TempretureListInput();
vilket ger datumet temperaturen recordades och vilken ordning den skapades i och lägger in  det i vectorn
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

på rad 181–194
Case 5 – visualisering av datan (printar "*" för temperaturvärdet).
denna går igenom vectorn och med en simlpe calculering går en for loop och printar "*" så man ser visuellt skillnaden på temperatur värdena
{
	void TempretureVisulisation(const std::vector<Measurement>& MeasurmentList)
	{
	    // går genom alla vectorer
	    for (int i = 0; i < size(MeasurmentList); i++)
	    {
	        int temp = round(MeasurmentList[i].TepretureInput);
	        for (int i = 0; i < round(temp / 2); i++) // for loopen printar "*" så att man kan se visualiserat hur tempraturen går ne och up
	        {
	            std::cout << "*";
	            //andvänder den här för att den inte bara pruntar ut alla "*" på en gång
	            this_thread::sleep_for(chrono::seconds(1));
	        }
	        std::cout << "   " << MeasurmentList[i].TepretureInput << " C" << endl;
	        std::cout << "\n";
	    }
	}
}

på rad 195–197
Case 6 – avslutar programmet (sätter run = false).
gör att run boolen blir false vilket avslutar programet

på rad 198–201
default – om man skriver ett nummer som inte är en del av menyn, skriver den ut att man ska skriva en ny input.
