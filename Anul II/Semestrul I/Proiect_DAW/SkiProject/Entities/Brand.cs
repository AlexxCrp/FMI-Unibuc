using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Entities
{
    public class Brand
    {
        public string Id { get; set; }
        public string Name { get; set; }

        public ICollection<Ski> Skis { get; set; }
    }
}
