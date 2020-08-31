#include "../inc/integracaoGrafoPlano.hpp"

IntegracaoGrafoPlano::IntegracaoGrafoPlano(){
    for (int i = 0; i < getV(); i++) {
            contaminado[i] = false;
            bloqueado[i] = false;
    }
}

IntegracaoGrafoPlano::~IntegracaoGrafoPlano() {
    	delete contaminado;
        delete bloqueado;
}

IntegracaoGrafoPlano IntegracaoGrafoPlano::contruirMapaGrafo() {

    IntegracaoGrafoPlano MapaNo;

/*
    Essa seria a integração dos nós
       *  *  *
        \ | /
       *- 0 -*
        / | \
       *  *  *
*/

    for(int i = 0; i<=MAX_VALUE; i++) {
        for (int j = 0; j<=MAX_VALUE; j++) {

            //TODO integração das laterais

            if (i > 0 && i < 39 && j > 0 &&j < 39) {
                MapaNo.addEdge((40*i)+j,(40*(i-1))+j-1);  /* lado \  */
                MapaNo.addEdge((40*i)+j,(40*(i-1))+j);    /* lado |  */
                MapaNo.addEdge((40*i)+j,(40*(i-1))+j+1);  /* lado /  */
                MapaNo.addEdge((40*i)+j,(40*i)+j+1);      /* lado -  */
                MapaNo.addEdge((40*i)+j,(40*(i+1))+j+1);  /* lado \  */
                MapaNo.addEdge((40*i)+j,(40*(i+1))+j);    /* lado |  */
                MapaNo.addEdge((40*i)+j,(40*(i+1))+j-1);  /* lado /  */
                MapaNo.addEdge((40*i)+j,(40*(i))+j-1);    /* lado -  */

            }
        }
    }

    return MapaNo;
}

bool IntegracaoGrafoPlano::getContaminado(int no) {
    return contaminado[no];
}
void IntegracaoGrafoPlano::setContaminado(int no, bool status) {
    contaminado[no] = status;
}

bool IntegracaoGrafoPlano::getBloqueio(int no) {
    return bloqueado[no];
}
void IntegracaoGrafoPlano::setBloqueio(int no, bool status) {
    bloqueado[no] = status;
}
