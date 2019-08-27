using System;
using System.Collections.Generic;
using System.Text;

namespace _02.Builder
{
    internal class House
    {
        private readonly List<object> _parts = new List<object>();

        public void Add(object part)
        {
            _parts.Add(part);
        }

        public override string ToString()
        {
            var descriptionBuilder = new StringBuilder($"House consists of:{Environment.NewLine}");

            _parts.ForEach(p => descriptionBuilder.AppendLine(p.ToString()));

            return descriptionBuilder.ToString();
        }
    }
}