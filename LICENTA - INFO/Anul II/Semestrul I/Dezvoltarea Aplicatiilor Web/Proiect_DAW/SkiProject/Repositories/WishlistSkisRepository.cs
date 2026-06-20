using SkiProject.Entities;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Repositories
{
    public class WishlistSkisRepository : IWishlistSkisRepository
    {
        private SkiProjectContext db;

        public WishlistSkisRepository(SkiProjectContext db)
        {
            this.db = db;
        }

        public IQueryable<WishlistSki> GetWishlistSkisIQueriable()
        {
            var wishlistSkis = db.WishlistSkis;
            return wishlistSkis;
        }

        public void Create(WishlistSki wishlistSki)
        {
            db.WishlistSkis.Add(wishlistSki);
            db.SaveChanges();
        }
/*
        public void Update(WishlistSki wishlistSki)
        {
            db.WishlistSkis.Update(wishlistSki);
            db.SaveChanges();
        }
*/
        public void Delete(WishlistSki wishlistSki)
        {
            db.WishlistSkis.Remove(wishlistSki);
            db.SaveChanges();
        }
    }
}
