using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Entities
{
    public class Wishlist
    {
        public string Id { get; set; }
        public virtual ICollection<WishlistSki> WishlistSkis { get; set; }

        public string UserId { get; set; }
        public virtual User User { get; set; }
    }
}

