# include <iostream>

void setup(int uplim, const char* name,TCanvas *c1,int spot) {
    // Makes stack for histograms
    
    TF1 *hist100 = new TF1("hist100","exp(-0.01*x)",0.,uplim);
    TF1 *hist10 = new TF1("hist10","exp(-0.1*x)",0.,uplim);
    TF1 *hist1 = new TF1("hist1","exp(-1*x)",0.,uplim);
    TF1 *hist01 = new TF1("hist01","exp(-10*x)",0.,uplim);
    
    // Sets up individual histograms
    TH1F *vis = new TH1F("vis","Decay Histogram",100,0,uplim);
    vis->SetLineColor(kRed);
    TH1F *vis10 = new TH1F("vis10","Decay Histogram",100,0,uplim);
    vis10->SetLineColor(kGreen);
    TH1F *vis1 = new TH1F("vis1","Decay Histogram",100,0,uplim);
    vis1->SetLineColor(kBlue);
    TH1F *vis01 = new TH1F("vis01","Decay Histogram",100,0,uplim);
    vis01->SetLineColor(kBlack);
    
    
    // Fills histograms
    vis->FillRandom("hist100", 100000);
    vis10->FillRandom("hist10", 100000);
    vis1->FillRandom("hist1", 100000);
    vis01->FillRandom("hist01", 100000);
    
    // Adds to stack and draws
    THStack *result = new THStack("result",name);
    
    result->Add(vis);
    result->Add(vis10);
    result->Add(vis1);
    result->Add(vis01);
    
    c1->cd(spot);
    result->Draw("nostack");
    //return result;
    
}

void Decay10km() {
    TCanvas *c1 = new TCanvas("c1","c1");
    c1->Divide(1,3);
    setup(100, "Decay Histogram 100m", c1, 1);
    setup(10000,"Decay Historgram 10km", c1, 2);
    setup(100000,"Decay Histogram 100km", c1, 3);
}

int main(){
    Decay10km();
}

