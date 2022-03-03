using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Entities
{
    public class Ski
    {
        public string Id { get; set; }

        public string Name { get; set; }

        public string Price { get; set; }

        public string PictureUrl { get; set; }

        public string BrandId { get; set; }

        public Brand Brand { get; set; }

        public virtual ICollection<WishlistSki> WishlistSkis { get; set; }
    }
}
