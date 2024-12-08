using Day7_Part1;
using System.Runtime.Serialization.Formatters;

var fstream = File.OpenText("./dataset.txt");

long result = 0;
bool isEqual = false;
List<IOperator> operators =
[
    new Addition(),
    new Multiplication(),
    new Concatenation()
];
while(!fstream.EndOfStream)
{
    string? line = fstream.ReadLine();
    if (line == null) return;
    string[] splited = line.Split(':');
    long testValue = long.Parse(splited[0]);
    splited = splited[1].Trim().Split(' ');
    List<long> operands = [];
    foreach (string str in splited)
        operands.Add(long.Parse(str));
    long first = 0;
    List<int> which = new (operands.Count - 1);
    for (int i = 0; i < operands.Count; i++)
        which.Add(0);
    while (true)
    {
        first = operands[0];
        for (int i = 1; i < operands.Count; i++)
        {
            long second = operands[i];
            first = operators[which[i - 1]].Calculate(first, second);
        }
        if (first == testValue)
        {
            isEqual = true;
            break;
        }
        if (which[which.Count - 1] == operators.Count - 1)
        {
            isEqual = false;
            break;
        }
        for (int i = 0; i < which.Count; i++)
        {
            if (which[i] == operators.Count - 1) which[i] = 0;
            else
            {
                which[i] = which[i] + 1;
                break;
            }
        }
    }
    if (isEqual) result += first;
}
Console.WriteLine(result);