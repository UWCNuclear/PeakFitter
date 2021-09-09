# PeakFitter example

To install git, paste in your terminal:

    sudo apt-get install git

To download PeakFitter, paste:

    git clone https://github.com/UWCNuclear/PeakFitter.git

To run PeakFitter, open your .root file containting your histogram:

    grsisort -l histogram.root
    
and then paste the following line in the GRSISort terminal:

    .x tpeakfitterExample.C
    
You need to edit the name of the histogram, the ranges and the centroids of the peaks (and, if required, the number of peaks).
