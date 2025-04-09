#include <iostream>

/* it could’ve been written more cleanly with dynamic arrays in heap memory(new) or with vectors,
   but I didn’t use them since they haven’t been taught yet */

int main()
{
    int FirstMatRow, FirstMatCol, SecondMatRow, SecondMatCol;
    std::cout<<"enter the number of first matrix row : ";
    std::cin>>FirstMatRow;
    std::cout<<"enter the number of first matrix column : ";
    std::cin>>FirstMatCol;
    double matrix1[FirstMatRow][FirstMatCol];
    for(int InputRow=0; InputRow<FirstMatRow; InputRow++)
    {
        for(int InputCol=0; InputCol<FirstMatCol; InputCol++)
        {
            std::cout<<"enter ("<<InputRow+1<<","<<InputCol+1<<") : ";
            std::cin>>matrix1[InputRow][InputCol];
        }
    }

    for(int OutputRow=0; OutputRow<FirstMatRow; OutputRow++)
    {
        for(int OutputCol=0; OutputCol<FirstMatCol; OutputCol++)
        {
            std::cout<<matrix1[OutputRow][OutputCol]<<"\t";
        }
        std::cout<<"\n\n\n";
    }
    std::cout<<"\n--------------------------------------------------------------------------------\n\n";
    GetSecond:
    std::cout<<"enter the number of second matrix row : ";
    std::cin>>SecondMatRow;
    if(FirstMatCol == SecondMatRow)
    {    
        std::cout<<"enter the number of second matrix column : ";
        std::cin>>SecondMatCol;
        double matrix2[SecondMatRow][SecondMatCol];
        for(int InputRow=0; InputRow<SecondMatRow; InputRow++)
        {
            for(int InputCol=0; InputCol<SecondMatCol; InputCol++)
            {
                std::cout<<"enter ("<<InputRow+1<<","<<InputCol+1<<") : ";
                std::cin>>matrix2[InputRow][InputCol];
            }
        }

        for(int OutputRow=0; OutputRow<SecondMatRow; OutputRow++)
        {
            for(int OutputCol=0; OutputCol<SecondMatCol; OutputCol++)
            {
                std::cout<<matrix2[OutputRow][OutputCol]<<"\t";
            }
            std::cout<<"\n\n\n";
        }
        std::cout<<"\n--------------------------------------------------------------------------------\n\n";
        double MultOfMatrices[FirstMatRow][SecondMatCol];
        std::cout<<"multiple of matrices is :\n";
        for(int MoveInRows=0; MoveInRows<FirstMatRow; MoveInRows++)
        {
            for(int MoveInColumns=0; MoveInColumns<SecondMatCol; MoveInColumns++)
            {
                for(int MoveToSum=0; MoveToSum<FirstMatCol; MoveToSum++)
                {
                    MultOfMatrices[MoveInRows][MoveInColumns] += matrix1[MoveInRows][MoveToSum]*matrix2[MoveToSum][MoveInColumns];
                }
                std::cout<<MultOfMatrices[MoveInRows][MoveInColumns]<<"\t";
            }
            std::cout<<"\n\n\n";
        }
        std::cout<<"\n\n\n";
    }
    else
    {
        std::cout<<"\nsecond matrix row must be equal to first matrix column\n\n";
        goto GetSecond;  // or can use While or DoWhile with continue and break
    }
}
//MadMad_80