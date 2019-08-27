using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01.Adapter
{
    class ProviderC : Provider
    {
        private readonly AdvancedProvider _provider;

        public ProviderC()
        {
            _provider = new AdvancedProvider();
        }

        public override void Do()
        {
            _provider.Make();
        }
    }
}
