void make_binnedgraph()
{
    vector<Double_t> vecbinContentse;
    vector<Double_t> vecbinContentsmu;
    vector<Double_t> vecbinEdges;
    vector<Double_t> vecbinErrorse;
    vector<Double_t> vecbinErrorsmu;

    fstream file_e;
    fstream file_mu;
    
    //file_e.open("eventrate_e.dat",ios::in);
    //file_mu.open("eventrate_mu.dat",ios::in);
    file_e.open("eventrate_e_ctautau_1.0e-24.dat",ios::in);
    file_mu.open("eventrate_mu_ctautau_1.0e-24.dat",ios::in);

    Double_t x,y,res;

    while(x<8)
    {
        file_e >> x >> y >> res;
        vecbinContentse.push_back(y);
        vecbinErrorse.push_back(res);
        vecbinEdges.push_back(x);
        file_mu >> x >> y >> res;
        vecbinContentsmu.push_back(y);
        vecbinErrorsmu.push_back(res);
        if(file_e.eof()) break;
    }

    Double_t binContentse[vecbinContentse.size()];
    Double_t binContentsmu[vecbinContentsmu.size()];
    Double_t binErrorse[vecbinErrorse.size()];
    Double_t binErrorsmu[vecbinErrorsmu.size()];
    Double_t binEdges[vecbinEdges.size()];
    for (size_t i = 0; i < vecbinEdges.size(); ++i) {
        binContentse[i] = vecbinContentse[i];
        binContentsmu[i] = vecbinContentsmu[i];
        binErrorse[i] = vecbinErrorse[i];
        binErrorsmu[i] = vecbinErrorsmu[i];
        binEdges[i] = vecbinEdges[i];
    }
    
    file_e.close();
    file_mu.close();
    
    int numBinse = sizeof(binContentse) / sizeof(binContentse[0]) - 1;
    int numBinsmu = sizeof(binContentsmu) / sizeof(binContentsmu[0]) - 1;

    TH1D *hist_e = new TH1D("hist", "Event Rate", numBinse,binEdges);
    TH1D *hist_mu = new TH1D("hist", "Event Rate", numBinsmu,binEdges);

    for (Int_t i = 0; i < numBinse; ++i) {
        hist_e->SetBinContent(i+1, binContentse[i]);
    }
    for (Int_t i = 0; i < numBinsmu; ++i) {
        hist_mu->SetBinContent(i+1, binContentsmu[i]);
    }

    hist_e->SetStats(0);
    hist_mu->SetStats(0);


    TCanvas *canvas_e = new TCanvas("canvas", "Binned Graph", 800, 600);

    hist_e->GetXaxis()->SetTitle("Energy");
    hist_e->GetYaxis()->SetTitle("Event Rate");
    hist_e->SetTitle("Energia x tx. de eventos no canal de aparecimento do nu e");
    hist_e->Draw();

    //canvas_e->SaveAs("eventratebingraph_e.png");
    canvas_e->SaveAs("eventratebingraph_e_ctautau_1.0e-24.png");

    TCanvas *canvas_mu = new TCanvas("canvas", "Binned Graph", 800, 600);

    hist_mu->GetXaxis()->SetTitle("Energy");
    hist_mu->GetYaxis()->SetTitle("Event Rate");
    hist_mu->SetTitle("Energia x tx. de eventos no canal de desaparecimento do nu mu");
    hist_mu->Draw();

    //canvas_mu->SaveAs("eventratebingraph_mu.png");
    canvas_mu->SaveAs("eventratebingraph_mu_ctautau_1.0e-24.png");

}
