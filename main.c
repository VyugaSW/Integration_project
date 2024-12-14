#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

#include "numFuncsIntegrations.h"
#include "functions.h"
#include "communicationModule.h"


#define LENGTH_AVAILABLE_FUNCTIONS 3
#define LENGTH_AVAILABLE_INTEGRATIONS_METHODS 4
#define LENGTH_AVAILABLE_ADAPTIVE_METHODS 2

int main(){
    setlocale(LC_CTYPE,"Russian");

    /*
     * Ðàçëè÷íûå ïåðå÷èñëåíèÿ enum, ðåàëèçîâàííûå â communicationModule.h,
     * ñîîòâåòñòâóþò èíäåêñàì ìàññèâîâ available - äîñòóïíûìè ôóíêöèÿ/ìåòîäàìè èíòåãðèðîâàíèÿ/àäàïòèâíûìè ìåòîäàìè
    */
    const char *avalaibleFunctions[LENGTH_AVAILABLE_FUNCTIONS] = {
        "a*e^{b*x}",
        "a+b*x+c*x^{2}+...+f*x^{9}",
        "A*sin(x+phi)"
    };

    const char *availableIntegrationsMethods[LENGTH_AVAILABLE_INTEGRATIONS_METHODS] = {
        "Ìåòîä ëåâûõ ïðÿìîóãîëüíèêîâ",
        "Ìåòîä ïðàâûõ ïðÿìîóãîëüíèêîâ",
        "Ìåòîä ñðåäíèõ ïðÿìîóãîëüíèêîâ",
        "Ìåòîä ïàðàáîë"
    };

    const char *availableAdaptiveMethods[LENGTH_AVAILABLE_ADAPTIVE_METHODS] = {
        "Àäàïòèâíûé ìåòîä",
        "Íåàäàïòèâíûé ìåòîä"
    };

    ETypeFunction choosenTypeFunction = chooseFunction(avalaibleFunctions,LENGTH_AVAILABLE_FUNCTIONS);

    size_t length_p = 0;
    fnc_t *choosenFunction = NULL;

    switch (choosenTypeFunction)
    {
        case SINUSOIDAL:
            length_p = PARAMS_SINUSOIDAL;
            choosenFunction = sinusoidal_func;
            break;
        case EXPONENTIAL:
            length_p = PARAMS_EXPONENTIAL;
            choosenFunction = exponential_func;
            break;
        case DEGREES:
            length_p = PARAMS_DEGREES;
            choosenFunction = degrees_func;
            break;
        default:
            break;
    }

    double p[length_p];
    getParams(p,length_p,avalaibleFunctions[choosenTypeFunction]);

    ETypeIntegration choosenTypeIntegration = chooseIntegrationMethod(availableIntegrationsMethods,LENGTH_AVAILABLE_INTEGRATIONS_METHODS);

    qf_t *choosenIntegration = NULL;
    switch (choosenTypeIntegration)
    {
        case LEFTRECTANGLES:
            choosenIntegration = left_rectangles_integration;
            break;
        case RIGHTRECTANGLES:
            choosenIntegration = right_rectangles_integration;
            break;
        case MIDDLERECTANGLES:
            choosenIntegration = middle_rectangles_integration;
            break;
        case PARABOLAS:
            choosenIntegration = parabolas_integration;
            break;
        default:
            break;
    }

    ETypeMethod choosenAdaptiveMethod = chooseAdaptiveMethod(availableAdaptiveMethods, LENGTH_AVAILABLE_ADAPTIVE_METHODS);
    double result = 0;
    double a = 0;
    double b = 0;
    unsigned n = 0;
    double eps = 0;

    switch (choosenAdaptiveMethod)
    {
        case NOADAPTIVE:
            enterInterval(&a,&b);
            enterNumSplitSegments(&n);
            result = choosenIntegration(choosenFunction,p,a,b,n);

            printf("\nÐåçóëüòàò: %lf\n", result);
            printf("\nÒàáëèöà èíòåãðèðîâàíèÿ:\n");
            switch (choosenTypeIntegration)
            {
                case LEFTRECTANGLES:
                    print_table_rectangles(choosenFunction,p,a,b,n,0);
                    break;
                case RIGHTRECTANGLES:
                    print_table_rectangles(choosenFunction,p,a,b,n,0.5);
                    break;
                case MIDDLERECTANGLES:
                    print_table_rectangles(choosenFunction,p,a,b,n,1);
                    break;
                case PARABOLAS:
                    print_table_parabolas(choosenFunction,p,a,b,n);
                    break;
                default:
                    break;
            }

            break;

        case ADAPTIVE:
            enterInterval(&a,&b);
            enterEps(&eps);
            result = integration_iter(choosenIntegration,choosenFunction,p,a,b,eps);
            printf("\nÐåçóëüòàò: %lf\n", result);
            break;

        default:
            break;
    }

    return 0;
}
