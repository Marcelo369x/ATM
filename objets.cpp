#include<iostream>
#include <vector>
#include <variant>
#include <string>
using namespace std;

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

            if(option != 1 || 2){
                cout << "\n enter one valid election ('1' or '2'): ";
            }
        }while(option !=  1 || 2);
        return option;
    }
};



class banco{
    protected:
        vector<string>datos_cuenta;

    //public :
   /*bool verify_ifExist_account(){

    if(){
        
    }
    return  false;
    }*/






};
class cuenta{
    private:
    //variables de registrarte
    string correo_electronico;
    string contra;
    
    public:
        string user; 
        
        void credenciales(string fcorreo_electronico , string fcontra,string fuser ){
            correo_electronico = fcorreo_electronico;
            contra = fcontra ;
            user = fuser;

        }

        void showcredentials(){
            cout<< "------------------------------------------------------------\n";
            cout<< "|--su usuario:-------| \n" << user;
            cout << "\n\n";
            cout<< "|--su correo electronico:-------| \n" << correo_electronico;
            cout <<"\n\n";
            cout<< "|--su contra:-------| \n" ;
            
            for(int i=0; i< contra.length(); i++){
                cout <<"*";
            }
            cout<<"\n";
        }
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
};

int main(){
    string Mcorreo_electronico;
    string Mvalid_domains[]= {"gmail","yahoo","hotmail",};
    string Mvalid_domainExtensions[]={".com",".net",".tech",".org",".gov",".info",".edu",".biz"};
    int size_Mvalid_domainExtensions = size(Mvalid_domainExtensions);
    int size_Mvalid_domains = size(Mvalid_domains);
    string Mcontra;
    string Muser;
  
    cuenta Cuenta;
    atm ATM;

    ATM.PrintBanner();
    int option;
    
    int option =0;
    option  = ATM.MenuPrincipal();


    if(option == 1){
        cout<< "|--ingrese su nombre de usuario:-------| \n";
        cin >> Muser;
        cout << "\n";
    
        bool valid_emailAdress_arroba=false;
        bool valid_emailAdress_domain=false;
        bool valid_emailAdress_Extdomain=false;
        do{

            valid_emailAdress_arroba=false;
            valid_emailAdress_domain=false;
            valid_emailAdress_Extdomain=false;
                
            cout<< "|--ingrese su correo electronico:-------| \n";
            cin >> Mcorreo_electronico;

            

            size_t V_arrobaMcorreo_electronico = Mcorreo_electronico.find("@");

            if( V_arrobaMcorreo_electronico == string::npos){
                valid_emailAdress_arroba = true;
                    cout << "\n [!]:please enter the valid structure of youre email (didnt find: @)"<<endl;
            }
               
            if(!Cuenta.check_domain(Mvalid_domains, size_Mvalid_domains,Mcorreo_electronico)){
                valid_emailAdress_domain = true;
                string dominio = Cuenta.Save_domain(Mvalid_domains, size_Mvalid_domains,Mcorreo_electronico);
                cout << "\n [!]:please enter the valid structure of youre ema il (this domain  is not valid"<< "("<< dominio <<")"<<endl;

                }   
            
        
                if(!Cuenta.check_extdomain(Mvalid_domainExtensions, size_Mvalid_domainExtensions,Mcorreo_electronico)){
                    valid_emailAdress_Extdomain = true;
                    string Extdominio = Cuenta.Save_extdomain(Mvalid_domainExtensions, size_Mvalid_domainExtensions,Mcorreo_electronico);
                    cout << "\n [!]:please enter the valid structure of youre email (this domain extension is not valid"<< "("<< Extdominio <<")"<<endl;
                }

                break;
            }while(valid_emailAdress_arroba || valid_emailAdress_domain ||  valid_emailAdress_Extdomain);
        }
    else if (option == 2){
 cout <<"============registrarte==========\n";
 cout<< "ingrese su usuario\n";
 cout<< "\t|-";
 cin >> Muser;
cout <<"\ningrese su contraseña\n";
cout<< "\t|-";
getline(cin , Mcontra);
}

else{
    cout << "ingresa un opcion valida \n";
}



    cout<< "\n";
    cout<< "|--ingrese una contrase\xa4 a:---------| \n";
    cin >> Mcontra;

    Cuenta.credenciales(Mcorreo_electronico , Mcontra , Muser);

    Cuenta.showcredentials();

 system("pause");
 return 0 ;   
}