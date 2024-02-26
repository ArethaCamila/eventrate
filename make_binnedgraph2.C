void make_binnedgraph2()
{
    vector<Double_t> vecbinContents;
    vector<Double_t> vecbinContentsBSM;
    vector<Double_t> vecbinEdges;
    vector<Double_t> vecbinErrors;
    vector<Double_t> vecbinErrorsBSM;

    fstream file;
    fstream fileBSM;
    
    file.open("eventrate_e.dat",ios::in);
    fileBSM.open("eventrate_e_ctautau_1.0e-22.dat",ios::in);

    Double_t x,y,res;

    while(x<8)
    {
        file >> x >> y >> res;
        vecbinContents.push_back(y);
        vecbinErrors.push_back(res);
        vecbinEdges.push_back(x);
        fileBSM >> x >> y >> res;
        vecbinContentsBSM.push_back(y);
        vecbinErrorsBSM.push_back(res);
        if(file.eof()) break;
    }

    Double_t binContents[vecbinContents.size()];
    Double_t binContentsBSM[vecbinContentsBSM.size()];
    Double_t binErrors[vecbinErrors.size()];
    Double_t binErrorsBSM[vecbinErrorsBSM.size()];
    Double_t binEdges[vecbinEdges.size()];
    for (size_t i = 0; i < vecbinEdges.size(); ++i) {
        binContents[i] = vecbinContents[i];
        binContentsBSM[i] = vecbinContentsBSM[i];
        binErrors[i] = vecbinErrors[i];
        binErrorsBSM[i] = vecbinErrorsBSM[i];
        binEdges[i] = vecbinEdges[i];
    }
    
    file.close();
    fileBSM.close();
    
    int numBins = sizeof(binContents) / sizeof(binContents[0]) - 1;
    int numBinsBSM = sizeof(binContentsBSM) / sizeof(binContentsBSM[0]) - 1;

    TH1D *hist    = new TH1D("hist", "Event Rate", numBins,binEdges);
    TH1D *histBSM = new TH1D("hist", "Event Rate", numBinsBSM,binEdges);

    for (Int_t i = 0; i < numBins; ++i) {
        hist->SetBinContent(i+1, binContents[i]);
    }
    for (Int_t i = 0; i < numBinsBSM; ++i) {
        histBSM->SetBinContent(i+1, binContentsBSM[i]);
    }

    hist->SetStats(0);
    histBSM->SetStats(0);


    TCanvas *canvas = new TCanvas("canvas", "Binned Graph", 800, 600);

    histBSM->SetTitle("Energy #times event rate in the #nu_{e} appearance channel");
    hist->SetLineColor(kBlue);
    histBSM->SetLineColor(kRed);
    //hist->GetXaxis()->SetTitle("Energy");
    //hist->GetYaxis()->SetTitle("Event Rate");
    histBSM->GetXaxis()->SetTitle("Energy");
    histBSM->GetYaxis()->SetTitle("Event Rate");
    
    
    
    histBSM->Draw();
    hist->Draw("same");
    //hist->Draw();
    //histBSM->Draw("same");

    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(hist, "Standard", "f");
    legend->AddEntry(histBSM, "c_{#tau#tau}=10^{-22}", "f");
    legend->Draw();
    

    //canvas->SaveAs("eventratebingraph_e_StdBSM.png");
    canvas->SaveAs("eventrate_e_SmXctautau_1.0e-22_2.png");
}
