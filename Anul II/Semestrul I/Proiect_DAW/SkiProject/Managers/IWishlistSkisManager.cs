using SkiProject.Entities;
using SkiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Managers
{
    public interface IWishlistSkisManager
    {
        List<WishlistSki> GetWishlistSkis();
        WishlistSki GetWishlistSkiById(string wishlistId, string skiId);
        void Create(WishlistSkiModel model);
       // void Update(WishlistSkiModel model);
        void Delete(string wishlistId, string skiId);
    }
}
