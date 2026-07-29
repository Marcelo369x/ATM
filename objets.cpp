#include<iostream>
#include <vector>
#include <variant>
#include <string>
using namespace std;




struct datos{
    string correo_electronico;
     std::vector<string> valid_domains= {"gmail","yahoo","hotmail"};
     std::vector<string> valid_domainExtensions={".com",".net",".tech",".org",".gov",".info",".edu",".biz"};
    int size_valid_domainExtensions = size(valid_domainExtensions);
    int size_valid_domains = size(valid_domains);
    string contra;
    string user;
};



class atm{
    public:
        void PrintBanner(){
        cout << "\t\t\t\t\t\t   #    ####### #     #"<<endl;
        cout << "\t\t\t\t\t\t  # #      #    ##   ##  "<<endl;
        cout << "\t\t\t\t\t\t #   #     #    # # # # "<<endl;
        cout << "\t\t\t\t\t\t#     #    #    #  #  # "<<endl;
        cout << "\t\t\t\t\t\t#######    #    #     # "<<endl;
        cout << "\t\t\t\t\t\t#     #    #    #     # "<<endl;
        cout << "\t\t\t\t\t\t#     #    #    #     # "<<endl;

    }
    int option;
    int MenuPrincipal(){
        do{
            option =0 ;
            cout << "\n\n\t\t\t\t\t\t     1.Iniciar sesion"<<endl;
            cout << "\n\t\t\t\t\t\t      2.Registrarme"<<endl;
            cin >> option;

            if(option != 1 && option != 2){
                cout << "\n enter one valid election ('1' or '2'): ";
            }
        }while(option != 1 && option != 2);
        return option;
    }
};



class banco{
    private:
    struct baseDeDatos_usuarios{
    
        //cada columna representa los datos un usuario
        std::vector <string>usuario = {};
        std::vector <string>nombreCompleto = {};
        std::vector <int>DNI = {};
        std::vector <string>contras = {};
        std::vector <string>email = {};
        std::vector <string>fechaNacimiento = {};

        string  correo_electronico;
        string contra;
        string user;
    };

    baseDeDatos_usuarios bdd_usuarios;

    
   /*bool verify_ifExist_account(){

    if(){
        
    }
    return  false;
    }*/
   public :

   

    bool check_domain(string Fvalid_domains[], int columnas, string Fcorreo_electronico){

            for(int i = 0 ;i < columnas;i++){
                if( Fcorreo_electronico.find(Fvalid_domains[i]) != string::npos){
                    //dominio = Fvalid_domainExtensions[i]; //Mcorreo_electronico.substr(extdominio);
                    return true; 
                }
        }
        return false;
    }

    string Save_domain(string Fvalid_domains[], int columnas, string Fcorreo_electronico){

            for(int i = 0 ;i < columnas;i++){
                if( Fcorreo_electronico.find(Fvalid_domains[i]) != string::npos){
                    string dominio = Fvalid_domains[i]; //Mcorreo_electronico.substr(extdominio);
            
                    return dominio; 
                }
            }
            return "";

    } 

    bool check_extdomain(string Fvalid_domainExtencions[], int columnas, string Fcorreo_electronico){

            for(int i = 0 ;i < columnas;i++){
                if( Fcorreo_electronico.find(Fvalid_domainExtencions[i]) != string::npos){
                    //Extdominio = Mvalid_domainExtensions[i]; //Mcorreo_electronico.substr(extdominio);
            
                    return true; 
                }
            }
            return false;
    }

    string Save_extdomain(string Fvalid_domainExtencions[], int columnas, string Fcorreo_electronico){

        for(int i = 0 ;i < columnas;i++){
            if( Fcorreo_electronico.find(Fvalid_domainExtencions[i]) != string::npos){
                string Extdominio = Fvalid_domainExtencions[i]; //Mcorreo_electronico.substr(extdominio);
            
                return Extdominio; 
            }
        }
        return "";
    }

   void credenciales(string fcorreo_electronico , string fcontra,string fuser ){
        bdd_usuarios.correo_electronico = fcorreo_electronico;
        bdd_usuarios.contra = fcontra ;
        bdd_usuarios.user = fuser;

    }

    void showcredentials(){
            cout<< "------------------------------------------------------------\n";
            cout<< "|--su usuario:-------| \n" << bdd_usuarios.user;
            cout << "\n\n";
            cout<< "|--su correo electronico:-------| \n" << bdd_usuarios.correo_electronico;
            cout <<"\n\n";
            cout<< "|--su contra:-------| \n" ;
            
            for(int i=0; i< bdd_usuarios.contra.length(); i++){
                cout <<"*";
            }
            cout<<"\n";
        }





};
class cuenta{

    public:
         banco Banco;

     void registrarte(  datos& Data  ){
        cout<< "|--ingrese su nombre de usuario:-------| \n";
        cin >> Data.user;
        cout << "\n";
    
        bool valid_emailAdress_arroba=false;
        bool valid_emailAdress_domain=false;
        bool valid_emailAdress_Extdomain=false;
        do{

            valid_emailAdress_arroba=false;
            valid_emailAdress_domain=false;
            valid_emailAdress_Extdomain=false;
                
            cout<< "|--ingrese su correo electronico:-------| \n";
            cin >> Data.correo_electronico;

            

            size_t V_arrobaMcorreo_electronico = Data.correo_electronico.find("@");

            if( V_arrobaMcorreo_electronico == string::npos){
                valid_emailAdress_arroba = true;
                    cout << "\n [!]:please enter the valid structure of youre email (didnt find: @)"<<endl;
            }
               
            if(!Banco.check_domain(Data.valid_domains, Data.size_fvalid_domains,Data.correo_electronico)){
                valid_emailAdress_domain = true;
                string dominio = Banco.Save_domain(Data.valid_domains, Data.size_fvalid_domains,Data.fcorreo_electronico);
                cout << "\n [!]:please enter the valid structure of youre ema il (this domain  is not valid"<< "("<< dominio <<")"<<endl;

                }   
            
        
                if(!Banco.check_extdomain(Data.valid_domainExtensions, Data.size_valid_domainExtensions,Data.correo_electronico)){
                    valid_emailAdress_Extdomain = true;
                    string Extdominio = Banco.Save_extdomain(Data.valid_domainExtensions,Data.size_valid_domainExtensions,Data.correo_electronico);
                    cout << "\n [!]:please enter the valid structure of youre email (this domain extension is not valid"<< "("<< Extdominio <<")"<<endl;
                }

                break;
            }while(valid_emailAdress_arroba || valid_emailAdress_domain ||  valid_emailAdress_Extdomain);
     }   

     void Iniciar_sesion( datos& Data){
        cout <<"============iniciar sesion==========\n";
        cout<< "ingrese su usuario\n";
        cout<< "\t|-";
        cin >> Data.user;
        cout <<"\ningrese su contraseña\n";
        cout<< "\t|-";
        getline(cin , Data.contra);

    }
    

    
};



int main(){
    
    datos Datos;
    banco Banco;
    cuenta Cuenta;
    atm ATM;

    ATM.PrintBanner();
    
    int option =0;
    option  = ATM.MenuPrincipal();

    if(option == 1){
        Cuenta.registrarte( s );
        }
    else if (option == 2){
        Cuenta.Iniciar_sesion();
    }






    cout<< "\n";
    cout<< "|--ingrese una contrase\xa4 a:---------| \n";
    cin >> Mcontra;

    Banco.credenciales(Mcorreo_electronico , Mcontra , Muser);

    Banco.showcredentials();

 system("pause");
 return 0 ;   
}