using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Entities
{
    public class WishlistSki
    {
        public string WishlistId { get; set; }
        public string SkiId { get; set; }

        public virtual Wishlist Wishlist { get; set; }
        public virtual Ski Ski { get; set; }
    }
}
