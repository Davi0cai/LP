#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../include/Produto.h"
#include "../include/ItemPedido.h"
#include "../include/Combo.h"
#include "../include/Cardapio.h"
#include "../include/Loader.h"
#include "../include/Pedido.h"
#include "../include/Sistema.h"


using namespace std;

void opcoes();

int main()
{
    int escolhaAcao = 0;
    Sistema sis;
    vector<Entregador> salvar;
    Cardapio cardapioGeral("Cardápio");
    Loader loadnsave;
    Pedido p;

    vector<Entregador> temp;

    //Tudo deve ficar entre as linhas de load e save
    loadnsave.cLoadSequence(cardapioGeral);
    loadnsave.cLoadEntregadores(temp);
    sis.setEntregadores(temp);

    //sis.addEntregadorSistema();

    //sis.addPedidoMesa(10, cardapioGeral);
    //sis.addPedidoEntrega(cardapioGeral);

    //cout << sis;

    do{
        opcoes();
        cin >> escolhaAcao;
        switch(escolhaAcao){
            case 1: {
                cout << cardapioGeral;
            }
            break;
            case 2: {
                cin >> cardapioGeral;
            }
            break;
            case 3: {
                int escolha;
                cout << "Remover produto (1) ou combo (2)? ";
                cin >> escolha;
                if(escolha == 1){
                    cout << "ID do produto a remover? ";
                    cin >> escolha;
                    cardapioGeral.removeProduto(escolha);
                }else if(escolha == 2){
                    cout << "ID do combo a remover? ";
                    cin >> escolha;
                    cardapioGeral.removeCombo(escolha);
                }else cout << "Escolha inválida.\n";
            }
            break;

            case 4: {
                int escolha;
                cout << "Pedido para qual mesa (0-19)? ";
                cin >> escolha;

                cin.ignore();
                sis.addPedidoMesa(escolha, cardapioGeral);
            }
            break;
            case 5: {
                int escolha;
                cout << "Finalizar pedido de qual mesa (0-19)? ";
                cin >> escolha;

                sis.mesaEntregue(escolha);
            }
            break;
            case 6: {
                sis.addPedidoEntrega(cardapioGeral);
            }
            break;
            case 7: {
                int escolha;
                cout << "Atualizar status de qual entrega (ID)? ";
                cin >> escolha;

                sis.atualizarEntrega(escolha);
            }
            break;

            case 8: {
                cout << sis;
            }
            break;

            case 9: {
                sis.addEntregadorSistema();
            }
            break;
            case 10: {
                sis.removerEntregadorSistema();
            }
            break;
            case 0: {
                if(sis.getMesasAtuais() > 0 || sis.getEntregasAtuais() > 0){
                    cout << "Sistema só pode ser finalizado se não houver mais pedidos locais ou entregas a concluir.\n";
                    escolhaAcao = -1;
                } else cout << "Finalizado...";
            }
            break;
            default: cout << "Escolha inválida.\n";
        }
    }while(escolhaAcao != 0);

    salvar = sis.getEntregadores();
    loadnsave.cSaveEntregadores(salvar);
    loadnsave.cSaveSequence(cardapioGeral);

    return 0;
}

void opcoes(){
    cout << "1 - Expor Cardápio Atual | 2 - Adicionar Item ou Combo a Cardápio | 3 - Remover Item ou Combo do Cardápio" << endl;
    cout << "4 - Adicionar Pedido Local | 5 - Finalizar Pedido Local | 6 - Adicionar Entrega | 7 - Atualizar Status de Entrega | 8 - Expor Dados Atuais do Sistema" << endl;
    cout << "9 - Adicionar Entregador ao Sistema | 10 - Remover Entregador do Sistema | 0 - Fechar programa" << endl; 
}