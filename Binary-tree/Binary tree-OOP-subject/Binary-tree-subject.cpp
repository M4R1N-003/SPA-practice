#include <iostream>
#include <cstring>
using namespace std;
    
class binarno{
    public:
        int element;
        char predmet[100];
        binarno *lijevi, *desni;

            binarno(){
                lijevi=NULL;
                desni=NULL;
                element = 0;
            }

            void dodavanje(int broj, char polje[100]){
                binarno *novi, *zadnji=this;
                int dalje = 1;
                    if (element == 0) {
                        element = broj;
                        return;
                    }
                    
                    do{
                        if(broj > zadnji->element){
                            if(zadnji->desni != NULL){
                                zadnji=zadnji->desni;
                            }
                            else{
                                novi = new binarno;
                                zadnji->desni=novi;
                                novi->element = broj;
                                strcpy(novi->predmet, polje);
                                novi->desni=NULL;
                                novi->lijevi=NULL;
                                dalje = 0;
                            }
                        }

                        else{
                            if(zadnji->lijevi !=NULL){
                                zadnji=zadnji->lijevi;
                            }
                            else{
                                novi = new binarno;
                                zadnji->lijevi=novi;
                                novi->element = broj;
                                strcpy(novi->predmet, polje);
                                novi->desni = NULL;
                                novi->lijevi=NULL;
                                dalje = 0;
                            }
                        }    
                    } while (dalje==1);     
            }

            void ispis(binarno *cvor) {
                if (cvor != NULL) {
                    ispis(cvor->lijevi);
                    cout << cvor->element << "--->" << cvor->predmet << endl;;
                    ispis(cvor->desni);
                }
            }

            void pretrazivanje(binarno *cvor, int broj) {
                if (cvor == NULL) {
                    cout<<"Element nije pronadjen!"<<endl;
                    return;
                }
                else if(cvor->element == broj){
                    cout<<"Trazeni element je: "<<cvor->element<<endl;
                    cout<<"Predmet je: "<<cvor->predmet<<endl;
                    return;
                }
                else if(cvor->element<broj){
                    pretrazivanje(cvor->desni, broj);
                }
                else if(cvor->element>broj){
                    pretrazivanje(cvor->lijevi, broj);
                }
            }

            void deleteTree(binarno* node, binarno *roditelj, bool desni) 
            { 
                if (node == NULL) return;
                if(desni){
                    roditelj->desni=NULL;
                }
                else{roditelj->lijevi=NULL;}

                /* first delete both subtrees */
                deleteTree(node->lijevi, node, false); 
                deleteTree(node->desni, node, true); 
                
                /* then delete the node */
                cout << "\n Deleting node: " << node->element;
                cout << "\n Deleting node: " << node->predmet;
                delete node;
            }

            void brisanje(binarno *cvor, int broj) {
                if (cvor == NULL) {
                    cout<<"Element nije pronadjen!"<<endl;
                    return;
                }
                else if(cvor->desni->element == broj){
                    deleteTree(cvor->desni, cvor, true);
                    return;
                }
                else if(cvor->lijevi->element == broj){
                    deleteTree(cvor->lijevi, cvor, false);
                    return;
                }
                else if(cvor->element<broj){
                    brisanje(cvor->desni, broj);
                }
                else if(cvor->element>broj){
                    brisanje(cvor->lijevi, broj);
                }
            }
            
};
    binarno *objekt = new binarno;
int main(){
    int biranje;
    do{
        cout<<endl;
        cout<<"1-Dodavanje elementa!"<<endl;
        cout<<"2-Ispisivanje elemenata!"<<endl;
        cout<<"3-Pretrazivanje elemenata!"<<endl;
        cout<<"4-Brisanje elemenata!"<<endl;
        cout<<"9-Kraj programa!"<<endl;
        cout<<endl;
        cout<<"Unesite izbor: ";
        cin>>biranje;
            switch(biranje){
                case 1:
                int broj;
                char polje[100];
                cout<<"Unesi element stabla: ";
                cin>>broj;
                cin.ignore();
                cout<<"Unesi predmet: ";
                cin.getline(polje, 100);
                objekt->dodavanje(broj, polje);
                    break;
                case 2:
                objekt->ispis(objekt);
                    break;
                case 3:
                int broj1;
                cout<<"Unesite broj za pretragu: ";
                cin>>broj1;
                objekt->pretrazivanje(objekt, broj1);
                    break;
                case 4:
                int broj2;
                cout<<"Unesite broj za dealokaciju: ";
                cin>>broj2;
                objekt->brisanje(objekt, broj2);
                    break;
                case 9:
                    cout<<"Kraj programa!"<<endl;
                    break;
                default:
                cout<<"Unesite ponovno!"<<endl;
                    break;
            }
    }while(biranje!=9);

    return 0;
}