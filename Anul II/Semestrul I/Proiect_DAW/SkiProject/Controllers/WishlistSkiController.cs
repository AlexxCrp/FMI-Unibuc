using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using SkiProject.Entities;
using SkiProject.Managers;
using SkiProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace SkiProject.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class WishlistSkiController : ControllerBase
    {
        private readonly IWishlistSkisManager manager;

        public WishlistSkiController(IWishlistSkisManager wishlistSkisManager)
        {
            this.manager = wishlistSkisManager;
        }

        [HttpGet]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> GetWishlistSkis()
        {
            var skis = manager.GetWishlistSkis();

            return Ok(skis);
        }        

        [HttpGet("byId/{id}")]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> GetById([FromRoute] string id1, string id2)
        {
            var ski = manager.GetWishlistSkiById(id1, id2);

            return Ok(ski);
        }

        [HttpPost]
        //[Authorize(Policy = "Admin+User")]
        public async Task<IActionResult> Create([FromBody] WishlistSkiModel wishlistSkiModel)
        {
            manager.Create(wishlistSkiModel);

            return Ok();
        }
/*
        [HttpPut]
        //[Authorize(Policy = "Admin")]
        public async Task<IActionResult> Update([FromBody] WishlistSkiModel wishlistSkiModel)
        {
            manager.Update(wishlistSkiModel);

            return Ok();
        }
*/
        [HttpDelete("{id1}/{id2}")]
       // [Authorize(Policy = "Admin")]
        public async Task<IActionResult> Delete([FromRoute] string id1, string id2)
        {
            manager.Delete(id1, id2);

            return Ok();
        }
    }
}
