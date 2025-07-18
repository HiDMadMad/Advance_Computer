#include <iostream>

int main()
{
    int MatsRow, MatsCol;
    std::cout<<"enter the number of matrices row : ";
    std::cin>>MatsRow;
    std::cout<<"enter the number of matrices column : ";
    std::cin>>MatsCol;
    std::cout<<"\n--------------------------------------------------------------------------------\n\nfirst matrix :\n";
    double matrix1[MatsRow][MatsCol];
    for(int InputRow=0; InputRow<MatsRow; InputRow++)
    {
        for(int InputCol=0; InputCol<MatsCol; InputCol++)
        {
            std::cout<<"enter ("<<InputRow+1<<","<<InputCol+1<<") = ";
            std::cin>>matrix1[InputRow][InputCol];
        }
    }

    for(int OutputRow=0; OutputRow<MatsRow; OutputRow++)
    {
        for(int OutputCol=0; OutputCol<MatsCol; OutputCol++)
        {
            std::cout<<matrix1[OutputRow][OutputCol]<<"\t";
        }
        std::cout<<"\n\n\n";
    }
    std::cout<<"\n--------------------------------------------------------------------------------\n\nsecond matrix :\n";
    double matrix2[MatsRow][MatsCol];
    for(int InputRow=0; InputRow<MatsRow; InputRow++)
    {
        for(int InputCol=0; InputCol<MatsCol; InputCol++)
        {
            std::cout<<"enter ("<<InputRow+1<<","<<InputCol+1<<") = ";
            std::cin>>matrix2[InputRow][InputCol];
        }
    }

    for(int OutputRow=0; OutputRow<MatsRow; OutputRow++)
    {
        for(int OutputCol=0; OutputCol<MatsCol; OutputCol++)
        {
            std::cout<<matrix2[OutputRow][OutputCol]<<"\t";
        }
        std::cout<<"\n\n\n";
    }
    std::cout<<"\n--------------------------------------------------------------------------------\n\n";
    double SumOfMatrices[MatsRow][MatsCol];
    std::cout<<"sum of matrices is :\n";
    for(int MoveInColumns=0; MoveInColumns<MatsCol; MoveInColumns++)
    {
        for(int MoveInRows=0; MoveInRows<MatsRow; MoveInRows++)
        {
            SumOfMatrices[MoveInRows][MoveInColumns] = matrix1[MoveInRows][MoveInColumns]+matrix2[MoveInRows][MoveInColumns];
        }
    }
    for(int MoveInRows=0; MoveInRows<MatsRow; MoveInRows++)
    {
        for(int MoveInColumns=0; MoveInColumns<MatsCol; MoveInColumns++)
        {
            std::cout<<SumOfMatrices[MoveInRows][MoveInColumns]<<"\t";
        }
        std::cout<<"\n\n\n";
    }
    std::cout<<"\n\n\n";
}
//MadMad_68