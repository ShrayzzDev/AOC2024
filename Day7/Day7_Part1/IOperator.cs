using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day7_Part1
{
    internal interface IOperator
    {
        long Calculate(long left, long right);
    }
}
