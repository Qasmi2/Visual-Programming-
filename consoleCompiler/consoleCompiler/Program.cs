using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.CodeDom.Compiler;
using System.Diagnostics;
using Microsoft.CSharp;

namespace consoleCompiler
{
    class Program
    {
        public static object Keys { get; private set; }
        static string mystr = "NULL", compile = "NULL";
        static char ch;


        static void Main(string[] args)
        {

            do
            {
                Console.WriteLine("\t 1 - Press 1 to Write C# code : \n\t 2 - Press 5 to Write compile the code : \n\t    \n\t    Enter your Option : _   ");
                string str = Console.ReadLine();

                switch (str)
                {
                    case "1":
                        Console.WriteLine("............................................ \n Start Writting a code \n  ");
                        // start to Writting a Code 

                        mystr = getcode();

                        break;

                    case "5":
                        // start compile a code 

                        CSharpCodeProvider codeProvider = new CSharpCodeProvider();
                        ICodeCompiler icc = codeProvider.CreateCompiler();
                        // string Output = "Out.exe";
                        System.CodeDom.Compiler.CompilerParameters parameters = new CompilerParameters();


                        // send code(written by us) to compilier to check erro 
                        CompilerResults results = icc.CompileAssemblyFromSource(parameters, mystr);



                        if (results.Errors.Count > 0)
                        {

                            foreach (CompilerError CompErr in results.Errors)
                            {
                                compile = compile +
                                              "Line number " + CompErr.Line +
                                              ", Error Number: " + CompErr.ErrorNumber +
                                              ", '" + CompErr.ErrorText + ";" +
                                              Environment.NewLine + Environment.NewLine;
                                Console.WriteLine(compile);
                                Console.WriteLine("\n\n ------------------------------------------- ");

                               

                            
                            }
                        }

                        else
                        {
                            Console.WriteLine("Successful Compile");
                        }
                        break;




                    default:
                        Console.WriteLine("Invalid Entery ");
                        break;
                }

            } while (ch !='e');
        
            Console.ReadKey();


        }

        // Get Code  for compiling 
        public static string getcode()
        {
            string line;
            
                line = Console.ReadLine();
            
            return line;

        }
    }
}
