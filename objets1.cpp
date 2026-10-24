#include <iostream>
#include <vector>
#include <variant>
#include <string>
#include <array>
#include <fstream>
#include "json.hpp"
#include <chrono>
using namespace std;

using json = nlohmann::json;

struct datos
{
    string correo_electronico;
    std::vector<const string> valid_domains = {"gmail", "yahoo", "hotmail"};
    std::vector<const string> valid_domainExtensions = {".com", ".net", ".tech", ".org", ".gov", ".info", ".edu", ".biz"};
    int size_valid_domainExtensions = size(valid_domainExtensions);
    int size_valid_domains = size(valid_domains);
    string contra;
    int contra_size;

    string tipo_cuenta = "";
    string user;
    string fecha_deNacimiento = "";
    int SaldoDeApertura;
    string DataToDelete;

    void delete_data_ofemail()
    {

        correo_electronico = "";
        DataToDelete = "";
    }

    void delete_otherdata()
    {
        fecha_deNacimiento = "";
        SaldoDeApertura = 0;
        DataToDelete = "";
    }

    string contra_censurada()
    {
        string Contra_censurada = "";
        for (int i = 0; i < contra_size; i++)
        {
            Contra_censurada += "*";
        }

        return Contra_censurada;
    }
};

class gui_atm
{
public:
    void PrintBanner()
    {
        cout << "\t\t\t\t\t\t   #    ####### #     #" << endl;
        cout << "\t\t\t\t\t\t  # #      #    ##   ##  " << endl;
        cout << "\t\t\t\t\t\t #   #     #    # # # # " << endl;
        cout << "\t\t\t\t\t\t#     #    #    #  #  # " << endl;
        cout << "\t\t\t\t\t\t#######    #    #     # " << endl;
        cout << "\t\t\t\t\t\t#     #    #    #     # " << endl;
        cout << "\t\t\t\t\t\t#     #    #    #     # " << endl;
    }

    int login()
    {
        int option = 0;
        do
        {

            cout << "\n\n\t\t\t\t\t\t     1.Iniciar sesion" << endl;
            cout << "\n\t\t\t\t\t\t      2.Registrarme" << endl;
            cin >> option;

            if (option != 1 && option != 2)
            {
                cout << "\n enter one valid election ('1' or '2'): ";
            }
        } while (option != 1 && option != 2);
        return option;
    }

    void printMenuOptions()
    {

        cout << endl;
        cout << "\t\t\t\t _________________ \t\t _________________ " << endl
             << endl;
        cout << "\t\t\t\t|                 |\t\t|                 |" << endl;
        cout << "\t\t\t\t|   1.depositar   |\t\t|    2.retirar    |" << endl;
        cout << "\t\t\t\t _________________ \t\t _________________ " << endl;

        cout << "\t\t\t\t _________________ \t\t _________________ " << endl
             << endl;
        cout << "\t\t\t\t|                 |\t\t|                 |" << endl;
        cout << "\t\t\t\t|    3.estado     |\t\t| 4.transferencia |" << endl;
        cout << "\t\t\t\t _________________ \t\t _________________ " << endl
             << endl;

        cout << "\t\t\t\t\t\t selecione una opcion: " << endl;
    }
};

class banco
{
public:
    /*bool verify_ifExist_account(){

     if(){

     }
     return  false;
     }*/

    bool check_age(datos &Data)
    {

        const int año_actual = 2026;

        string dia_deNacimiento = Data.fecha_deNacimiento.substr(0, 2);
        int INTdia_deNacimiento = std::stoi(dia_deNacimiento);

        string mes_deNacimiento = Data.fecha_deNacimiento.substr(3, 2);
        int INTmes_deNacimiento = std::stoi(mes_deNacimiento);

        string año_deNacimiento = Data.fecha_deNacimiento.substr(7, 4);
        int INTaño_deNacimiento = std::stoi(año_deNacimiento);
        // 00/00/0000

        int edadActual = año_actual - INTaño_deNacimiento;

        if (edadActual < 18)
        {
            return false;
        }
        return true;
    }

    bool check_domain(datos &Data)
    {

        for (int i = 0; i < Data.size_valid_domains; i++)
        {
            if (Data.correo_electronico.find(Data.valid_domains[i]) != string::npos)
            {
                // dominio = Fvalid_domainExtensions[i]; //Mcorreo_electronico.substr(extdominio);
                return true;
            }
        }
        return false;
    }

    string Save_domain(datos &Data)
    {

        for (int i = 0; i < Data.size_valid_domains; i++)
        {
            if (Data.correo_electronico.find(Data.valid_domains[i]) != string::npos)
            {
                string dominio = Data.valid_domains[i]; // Mcorreo_electronico.substr(extdominio);

                return dominio;
            }
        }
        return "";
    }

    bool check_extdomain(datos &Data)
    {

        for (int i = 0; i < Data.size_valid_domainExtensions; i++)
        {
            if (Data.correo_electronico.find(Data.valid_domainExtensions[i]) != string::npos)
            {
                // Extdominio = Mvalid_domainExtensions[i]; //Mcorreo_electronico.substr(extdominio);

                return true;
            }
        }
        return false;
    }

    string Save_extdomain(datos &Data)
    {

        for (int i = 0; i < Data.size_valid_domainExtensions; i++)
        {
            if (Data.correo_electronico.find(Data.valid_domainExtensions[i]) != string::npos)
            {
                string Extdominio = Data.valid_domainExtensions[i]; // Mcorreo_electronico.substr(extdominio);

                return Extdominio;
            }
        }
        return "";
    }

    /* void credenciales(string fcorreo_electronico , string fcontra,string fuser ){
          bdd_usuarios.correo_electronico = fcorreo_electronico;
          bdd_usuarios.contra = fcontra ;
          bdd_usuarios.user = fuser;

      }*/

    void showcredentials(/*las recibe*/ string CACHE_user, string CACHE_correo, string CACHE_edad, datos &Data)
    {
        cout << "------------------------------------------------------------\n";
        cout << "|--su usuario:-------| \n"
             << CACHE_user << endl;
        ;
        cout << "\n\n";
        cout << "|--su correo electronico:-------| \n"
             << CACHE_correo << endl;
        ;
        cout << "\n\n";
        cout << "|--su contra:-------| \n";
        cout << Data.contra_censurada() << endl;

        int saldo = GETsaldo(CACHE_user);

        cout << "\t\t\t\t _____________________" << endl;
        cout << "\t\t\t\t|                                  |" << endl;
        cout << "\t\t\t\t|   saldo: " << saldo << "              |" << endl;
        cout << "\t\t\t\t _____________________ " << endl;
    }

    bool verificarSesionExistente(datos &Data)
    {

        json sesion;
        ifstream archivolectura("D:\\base_de_datos.json");

        sesion = json::parse(archivolectura);

        if (sesion[Data.user] != string::npos)
        {

            if (sesion[Data.user]["contraseña"] != string::npos)
            {
                return true;
            }
        }
        return false;
    }
    const int SaldoApertura_Minimo = 1000;
    bool verify_SaldoApertura(datos &Data)
    {

        if (Data.SaldoDeApertura < SaldoApertura_Minimo)
        {
            return false;
        }
        return true;
    }

    void agregarUnaNuevaCuenta(datos &Data)
    {
        json informacion;

        ifstream archivolectura("D:\\base_de_datos.json");
        if (archivolectura)
        {

            archivolectura >> informacion;
        }

        informacion[Data.user]["user"] = Data.user;
        informacion[Data.user]["tipo de cuenta"] = Data.tipo_cuenta;
        informacion[Data.user]["correo electronico"] = Data.correo_electronico;
        informacion[Data.user]["contraseña"] = Data.contra;
        informacion[Data.user]["saldo actual"] = Data.SaldoDeApertura;
        informacion[Data.user]["fecha de nacimiento"] = Data.fecha_deNacimiento;
        informacion[Data.user]["tramites"];
        ofstream archivo("D:\\base_de_datos.json");
        /*
        tramites:
            tipo:deposito
            dinero:700
            fecha:
                hora
                dia
                mes
                año

            leido:si

        */
        archivo << informacion.dump(4);
    }

    int GETsaldo(string CACHE_user)
    {

        ifstream archivelecture("D:\\base_de_datos.json");

        json input = json::parse(archivelecture);

        int saldo = input[CACHE_user]["saldo actual"];

        return saldo;
    }

    string GETcorreo(string CACHE_user)
    {

        ifstream archivelecture("D:\\base_de_datos.json");

        json input = json::parse(archivelecture);

        string correo = input[CACHE_user]["correo electronico"];

        return correo;
    }

    int GETfechaActual()
    {
        auto hoy = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
        std::chrono::year_month_day fecha{hoy};

        // 2. Obtener la hora del sistema con el tiempo restante del día
        std::chrono::hh_mm_ss hora{std::chrono::system_clock::now() - hoy};

        // 3. Extraer directamente a tus variables (retornan tipos numéricos de chrono)
        auto ano = fecha.year();
        auto mes = fecha.month();
        auto dia = fecha.day();

        auto horas = hora.hours();
    }

    void registrarTramites()
    {
    }

    void ActualizarSaldo(int Deposito, string CACHE_user)
    {
        int saldo = GETsaldo(CACHE_user);

        saldo += Deposito;

        json info;
        ifstream archlecture("D:\\base_de_datos.json");
        if (archlecture)
        {
            archlecture >> info;
        }

        info[CACHE_user]["saldo actual"] = saldo;

        ofstream archsalid("D:\\base_de_datos.json");
        archsalid << info;
    }

    void retirarDinero(int Retiro, string CACHE_user)
    {
        int saldo = GETsaldo(CACHE_user);

        saldo -= Retiro;

        json info;
        ifstream archlecture("D:\\base_de_datos.json");
        if (archlecture)
        {
            archlecture >> info;
        }

        info[CACHE_user]["saldo actual"] = saldo;

        ofstream archsalid("D:\\base_de_datos.json");
        archsalid << info;
    }

    void transaccion(/*user q envia y user q recibe*/)
    {
    }
};
class cuenta
{
protected:
    // varibles tipo cache , los datos de la cuenta se guardam aqui, pa no pedirselos a cafa rato a la bd
    // osea cuando estes ya adentro de la cuenta(sesion activa) se usan estos datos para disminuir latencia de pedir datos
    // protected para q los hijos pueden usarlos
    string cache_user;
    string cache_correo;
    string cache_edad;

public:
    banco &Banco;

    cuenta(banco &b) : Banco(b) {};

    datos Data;
    gui_atm gui_ATM;

    void registrarte(datos &Data)
    {
        cout << "======================REGISTRARTE====================" << endl;
        cout << "|--ingrese su nombre de usuario:-------| \n";
        cin >> Data.user;
        cout << "\n";

        cout << "|--ingrese una contraseña:-------| \n";
        cin >> Data.contra;
        cout << "\n";

        int Opcion_tipocuenta;
        cout << "|--------que tipo de cuenta desea hacer:--------|" << endl;
        cout << "[1]cuenta de ahorro" << endl;
        cout << "[2]cuenta corriente" << endl;
        cout << "[3]cuenta de nomina" << endl;
        cout << "\nescribe el numero de la opcion q elijas:" << endl;
        cin >> Opcion_tipocuenta;

        switch (Opcion_tipocuenta)
        {
        case 1:
            Data.tipo_cuenta = "cuenta de ahorro";
            break;
        case 2:
            Data.tipo_cuenta = "cuenta de nomina";
            break;

        case 3:
            Data.tipo_cuenta = "cuenta corriente";
            break;

        default:
            break;
        }

        bool valid_emailAdress_arroba = false;
        bool valid_emailAdress_domain = false;
        bool valid_emailAdress_Extdomain = false;
        bool valid_Age = false;
        bool valid_saldoDeApertura = false;

        do
        {

            valid_emailAdress_arroba = false;
            valid_emailAdress_domain = false;
            valid_emailAdress_Extdomain = false;

            cout << "|--ingrese su correo electronico:-------| \n";
            cin >> Data.correo_electronico;

            size_t V_arrobaMcorreo_electronico = Data.correo_electronico.find("@");

            if (V_arrobaMcorreo_electronico == string::npos)
            {
                valid_emailAdress_arroba = true;
                cout << "\n [!]:please enter the valid structure of youre email (didnt find: @)" << endl;
            }

            if (!Banco.check_domain(Data))
            {
                valid_emailAdress_domain = true;
                string dominio = Banco.Save_domain(Data);
                cout << "\n [!]:please enter the valid structure of youre ema il (this domain  is not valid" << "(" << dominio << ")" << endl;
            }

            if (!Banco.check_extdomain(Data))
            {
                valid_emailAdress_Extdomain = true;
                string Extdominio = Banco.Save_extdomain(Data);
                cout << "\n [!]:please enter the valid structure of youre email (this domain extension is not valid" << "(" << Extdominio << ")" << endl;
            }

            // if(!valid_emailAdress_arroba && !valid_emailAdress_domain &&  !valid_emailAdress_Extdomain){
            //   cache_correo = Data.correo_electronico;
            //}

            if (valid_emailAdress_arroba || valid_emailAdress_domain || valid_emailAdress_Extdomain)
            {
                Data.delete_data_ofemail();
            }
            else
            {
                cache_correo = Data.correo_electronico;
            }
        } while (valid_emailAdress_arroba || valid_emailAdress_domain || valid_emailAdress_Extdomain);

        do
        {
            valid_Age = false;
            valid_saldoDeApertura = false;

            cout << "ingrese un saldo inicial base para aperturar la cuenta (min : 1000lps )" << endl;
            cin >> Data.SaldoDeApertura;

            if (!Banco.verify_SaldoApertura(Data))
            {
                valid_saldoDeApertura = true;

                cout << "[!]el saldo minimo es de :" << Banco.SaldoApertura_Minimo << endl;
            }

            cout << "|--ingrese su fecha de nacimiento:-------| \n";
            cout << "|--en formato Dia/Mes/Año ,ej. 04/02/2008:-------| \n";
            cin >> Data.fecha_deNacimiento;

            if (!Banco.check_age(Data))
            {
                valid_Age = true;
            }

            if (valid_Age || valid_saldoDeApertura)
            {
                Data.delete_otherdata();
            }
            else
            {
                cache_edad = Data.fecha_deNacimiento;
                cache_user = Data.user;
            }
        } while (valid_Age || valid_saldoDeApertura);
        Data.contra_size = Data.contra.size();
    }

    void Iniciar_sesion(datos &Data)
    {
        cout << "============iniciar sesion==========\n";
        cout << "ingrese su usuario\n";
        cout << "\t|-";
        cin >> Data.user;
        cout << "\ningrese su contraseña\n";
        cout << "\t|-";
        cin >> Data.contra;

        if (Banco.verificarSesionExistente(Data))
        {

            cache_user = Data.user;
            cache_correo = Banco.GETcorreo(cache_user);
            Data.contra_size = Data.contra.size();
            menuPrincipal();
        }
        else
        {
            cout << "[!]cuenta inexistente \n[+]porfavor vuelva a intentarlo." << endl;
        }
    }

    virtual void retirarMoney(int retirar, string CACHEuser)
    {

        Banco.retirarDinero(retirar, CACHEuser);
    }
    void menuPrincipal()
    {
        int optionMENU = 0;
        int deposito = 0;
        int retiro = 0;
        gui_ATM.printMenuOptions();
        cin >> optionMENU;

        if (optionMENU != 1 && optionMENU != 2 && optionMENU != 3 && optionMENU != 4)
        {
            cout << "[!]invalid opcion" << endl;
        }
        switch (optionMENU)
        {
        case 1:

            cout << "ingrese cuanto de desea depositar a la cuenta:" << endl;
            cin >> deposito;

            Banco.ActualizarSaldo(deposito, cache_user);

            cout << "se a depositado" << endl;
            break;
        case 2:
            cout << "ingrese cuanto dinero desea retirar de la cuenta:" << endl;
            cin >> retiro;

            retirarMoney(retiro, cache_user);
            cout << "ha retirado '" << retiro << "' lps" << endl;
            break;
        case 3:
            cout << "====================ESTADO DE CUENTA====================" << endl;
            Banco.showcredentials(/*le paso prestado las var cache a este metodo */ cache_user, cache_correo, cache_edad, Data);
            break;
        case 4:
            cout << "funcion en creacion" << endl;

            break;
        }
    }
};

class cuenta_de_ahorro : public cuenta
{

public:
    banco &bank;
    cuenta_de_ahorro(banco &b) : cuenta(b), bank(b)
    {
    }

    int tablaDePorcentaje_intereses()
    {

        int saldo = Banco.GETsaldo(cache_user);

        if (saldo <= 3000)
        {

            return 0.25;
        }
        else if (saldo > 3000 && saldo < 10000)
        {

            return 0.50;
        }
        else if (saldo >= 10000 && saldo < 25000)
        {

            return 0.75;
        }
        else if (saldo >= 25000 && saldo < 70000)
        {

            return 1;
        }
        else if (saldo >= 70000 && saldo < 100000)
        {

            return 1.25;
        }
        else if (saldo >= 100000)
        {

            return 1.50;
        }
        else
        {
            return 0;
        }

        void retirarMoney(int retirar, string CACHEuser) override {
       
        }
    }
};

class cuenta_corriente : public cuenta
{
};

class cuenta_nomina : public cuenta
{
};

int main()
{

    datos Datos;
    banco Banco;
    gui_atm ATM;
    cuenta Cuenta(Banco);
    ATM.PrintBanner();

    int option = 0;
    option = ATM.login();

    if (option == 1)
    {
        Cuenta.Iniciar_sesion(Datos);
        if (Banco.verificarSesionExistente(Datos))
        {
            Cuenta.menuPrincipal();
        }
    }
    else if (option == 2)
    {
        Cuenta.registrarte(Datos);
        Banco.agregarUnaNuevaCuenta(Datos);
        Cuenta.menuPrincipal();
    }

    system("pause");
    return 0;
}