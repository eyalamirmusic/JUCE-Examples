#include "SubdivisionParam.h"

juce::StringArray getChoices()
{
    return {"1/1", "1/2", "1/4", "1/8", "1/16"};
}

SubdivisionParameter::SubdivisionParameter()
    : juce::AudioParameterChoice("Subdivision", "Subdivision", getChoices(), 3)
{
}

double SubdivisionParameter::getDivisionPPQ()
{
    switch (getIndex())
    {
        case 0:
            return 4.0;

        case 1:
            return 2.0;

        case 2:
            return 1.0;

        case 3:
            return 0.5;

        case 4:
            return 0.25;
    }

    return 1.0;
}
