using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Identity;

namespace SkiProject.Entities
{
    public class SkiProjectContext : IdentityDbContext<User, Role, string, IdentityUserClaim<string>,
        UserRole, IdentityUserLogin<string>, IdentityRoleClaim<String>, IdentityUserToken<string>>
    {
        public SkiProjectContext(DbContextOptions<SkiProjectContext> options) : base(options) { }
        public DbSet<Ski> Skis { get; set; }
        public DbSet<Brand> Brands { get; set; }
        public DbSet<Wishlist> Wishlists { get; set; }
        public DbSet<WishlistSki> WishlistSkis { get; set; }
       

        protected override void OnModelCreating(ModelBuilder builder)
        {
            base.OnModelCreating(builder);

            //One to One
            builder.Entity<User>()
                .HasOne(user => user.Wishlist)
                .WithOne(wishlist => wishlist.User);

            //One to Many
            builder.Entity<Brand>()
                .HasMany(a => a.Skis)
                .WithOne(b => b.Brand);

            //Many To Many
            builder.Entity<WishlistSki>().HasKey(ws => new { ws.WishlistId, ws.SkiId });

            builder.Entity<WishlistSki>()
                .HasOne(ws => ws.Wishlist)
                .WithMany(w => w.WishlistSkis)
                .HasForeignKey(ws => ws.WishlistId);

            builder.Entity<WishlistSki>()
                .HasOne(ws => ws.Ski)
                .WithMany(s => s.WishlistSkis)
                .HasForeignKey(ws => ws.WishlistId);
        }
    }
}
