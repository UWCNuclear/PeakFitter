# PeakFitter example

To install git, paste in your terminal:

    sudo apt-get install git

To download PeakFitter, paste:

    git clone https://github.com/UWCNuclear/PeakFitter.git

To run PeakFitter, type in the command line:

     grsisort -l histograms.root
    
and then the following line in the GRSISort terminal:

    .x tpeakfitterExample.C
    
You need to edit the name of the histogram and the range of the peaks (and, if required, the number of peaks).
