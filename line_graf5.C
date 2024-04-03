#include "TGraph.h"
#include "TCanvas.h"

void line_graf5() {
	TCanvas *c1 = new TCanvas(); // Instância da classe de tela
	auto sm =   new TGraph("prob_std_mu_for_e.dat"); // Instância de uma classe de gráfico
	auto bsm1 = new TGraph("prob_c_etau_1.0e-24_0.dat");   // zero
	auto bsm2 = new TGraph("prob_c_etau_1.0e-24_0.5.dat"); // meio
	auto bsm3 = new TGraph("prob_c_etau_1.0e-24_1.0.dat"); // um
	auto bsm4 = new TGraph("prob_c_etau_1.0e-24_1.5.dat"); // um e meio
// Fazer processamentos aqui se necessário
	c1->SetGrid();

//título 
    bsm1->SetTitle("Probability of Oscillation #nu_{#mu}->#nu_{e}");
    
//Definindo cor da linha
    sm->SetLineColor(kBlack);//cor da linha do sm
    bsm1->SetLineColor(kRed);
    bsm2->SetLineColor(kGreen);
    bsm3->SetLineColor(kBlue);
    bsm4->SetLineColor(6);//cor rosa
    
//eixos do gráfico
    bsm1->GetXaxis()->SetTitle("Energy (GeV)");
    bsm1->GetYaxis()->SetTitle("Probability");
    //sm->GetXaxis()->SetRangeUser(0,100);
    //sm->GetYaxis()->SetRangeUser(0,100);

//espessura da linha
    sm->SetLineWidth(2);//sm
    bsm1->SetLineWidth(2);
    bsm2->SetLineWidth(2);
    bsm3->SetLineWidth(2);
    bsm4->SetLineWidth(2);
    
//estilo da linha
    sm->SetLineStyle(2);//sm
    bsm1->SetLineStyle(1);
    bsm2->SetLineStyle(1);
    bsm3->SetLineStyle(1);
    bsm4->SetLineStyle(1);

    
//Para centralizar o título
    //sm->GetYaxis()->CenterTitle(true);
    //sm->GetXaxis()->SetTitleOffset(1.2);
    //sm->GetXaxis()->CenterTitle(true);
    //sm->GetYaxis()->SetTitleOffset(1.25);

	
    bsm1->Draw();
	  bsm2->Draw("same");
    bsm3->Draw("same");
    bsm4->Draw("same");
    sm->Draw("same");
    //hist->Draw();
    //histBSM->Draw("same");
   
//Criando legenda
    TLegend *legend = new TLegend(0.65, 0.65, 0.9, 0.9);
    legend->AddEntry(sm, "Standard", "f");
    legend->AddEntry(bsm1, "#phi_{e#tau} = 0 ", "f");
    legend->AddEntry(bsm2, "#phi_{e#tau} = #pi/2", "f");
    legend->AddEntry(bsm3, "#phi_{e#tau} = #pi", "f");
    legend->AddEntry(bsm4, "#phi_{e#tau} = 3#pi/2", "f");
    legend->SetHeader("#cbar c_{e#tau}#cbar = 10^{-24}", "C");
    legend->Draw();


	c1->Print("c_etau_1.0e-24.png"); // Método para "imprimir" (exportar)
}
