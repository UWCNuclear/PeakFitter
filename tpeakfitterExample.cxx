//Fitting with TPeakFitter

//Assuming that the histogram to fit is called myhist
//Can be used in command line or incorporated into a c++ code


// as an example, we'll fit two peaks at 511 and 513 keV
//initialize a TPeakFitter function between this region
TPeakFitter *a = new TPeakFitter(500,520); 
//make sure to give it some background in the region too to fit to

//initialize the peaks
a1 = new TRWPeak(511);
a2 = new TRWPeak(513);
//can also use TABPeak() if fitting addback spectra

//add the peaks to the fit function
a->AddPeak(a1);
a->AddPeak(a2);

//fit the TPeakFitter onto the histogram gE

a->Fit(myhist,"R");
//as usual, don't use the "L" flag for fitting gated/background subtracted spectra

//to access the fit parameters, call the following on the peak itself (not the entire TPeakFitter)
a1->GetFitFunction()->GetParameter(0);

//parameters:
// 0 - amplitude
// 1 - centroid
// 2 - sigma
// 3 - beta
// 4 - R
// 5 - step

//the above will initialize the peaks at 511 and 513, but it will let the centroids shift around
//to find the best fit

//if you know the centroids and want to keep them fixed, then you should also call

a1->GetFitFunction()->FixParameter(1,510.9);
a2->GetFitFunction()->FixParameter(1,513.4);
//before the fitting.

//similar to fixing the parameter, you can also set the parameter, fix the parameter bounds, and release a fixed parameter:

a1->GetFitFunction()->ReleaseParameter(1);
a1->GetFitFunction()->SetParLimits(1,510,512);
a1->GetFitFunction()->SetParameter(1,511);


//TPeakFitter has no problem fitting and 10+ peaks at once. It may take a few seconds, and the fit doesn't always converge
//for every peak, so it can take a couple of tries to get it to fit properly. 

