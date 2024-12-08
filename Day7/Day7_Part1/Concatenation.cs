using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Day7_Part1
{
    internal class Concatenation : IOperator
    {
        public long Calculate(long left, long right)
            => long.Parse(left.ToString() + right.ToString());
    }
}
