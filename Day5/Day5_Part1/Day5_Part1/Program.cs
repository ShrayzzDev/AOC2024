var fstream = File.OpenText("./dataset.txt");

var map = new Dictionary<int, List<int>>();

string? line = fstream.ReadLine();
while (!string.IsNullOrWhiteSpace(line))
{
    string[] readLine = line.Split('|');
    int firstInt = int.Parse(readLine[0]);
    int secondInt = int.Parse(readLine[1]);
    map.TryGetValue(secondInt, out var list);
    if (list == null)
    {
        var newList = new List<int>()
        {
            firstInt
        };
        map.Add(secondInt, newList);
    }
    else
        list.Add(firstInt);
    line = fstream.ReadLine();
}

int result = 0;
string[] numbers;
List<int> currentLine;
bool isValid;
while(!fstream.EndOfStream)
{
    line = fstream.ReadLine();
    currentLine = new List<int>();
    numbers = line.Split(',');
    isValid = true;
    var loaded = new List<int>();
    foreach (var item in numbers)
        loaded.Add(int.Parse(item));

    foreach (var current in loaded)
    {
        map.TryGetValue(current, out var toCheck);
        if (toCheck != null)
        {
            foreach (var check in toCheck)
                isValid &= (!(loaded.Contains(check) && loaded.Contains(current)) || currentLine.Contains(check));
            if (!isValid) break;
        }
        currentLine.Add(current);
    }
    if (isValid) result += currentLine[currentLine.Count / 2];
}

Console.WriteLine(result);
